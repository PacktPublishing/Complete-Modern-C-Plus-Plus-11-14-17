#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <format>
template<typename Container>
void Print(Container& container, std::string_view message = "", std::string_view sep = " ") {
	std::cout << "##### " << (message.empty() ? "Output" : message) << " #####\n";
	std::cout << "[ ";
	std::string_view tab = "";
	if (sep == "\n") {
		tab = "   ";
		std::cout << sep;
	}
	for (auto& e : container) {
		std::cout << tab << e << sep;
	}
	std::cout << "]\n\n";
}
struct Employee {
	std::string m_Name;
	int m_Id;
	std::string m_ProgLang;
public:
	Employee(const std::string& n, int id, const std::string& pl) :
		m_Name(n),
		m_Id(id),
		m_ProgLang(pl) {

	}
	const std::string& GetName()const {
		return m_Name;
	}
	int GetId()const {
		return m_Id;
	}
	const std::string& GetProgrammingLanguage()const {
		return m_ProgLang;
	}
	friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
		return os << std::format(
			"{:<6} {:<12} {:<6}",
			emp.m_Id,
			emp.m_Name,
			emp.m_ProgLang
		);
	}
};
struct EmpIds {
	std::vector<int> m_Ids;
	void operator()(const Employee& emp) {
		if (emp.GetProgrammingLanguage() == "C++")
			m_Ids.push_back(emp.GetId());
	}
};
void UserDefined() {
	std::vector<Employee> employees{
	Employee{"Umar", 101, "C++"},
	Employee{"Bob", 202, "Java"},
	Employee{"Joey", 200, "C++"},
	Employee{"Alice", 103, "Python"},
	Employee{"David", 105, "C++"},
	Employee{"Emma", 204, "Java"},
	Employee{"Charlie", 107, "Python"},
	Employee{"Sophia", 108, "C++"},
	Employee{"Michael", 210, "C#"},
	Employee{"Olivia", 212, "Java"},
	Employee{"Daniel", 115, "C++"},
	Employee{"Grace", 118, "Rust"}
	};
	//Use callback to avoid overloading comparison operators
	std::ranges::sort(employees, std::less{}, &Employee::m_Name);
	Print(employees, "Sorted Employees based on name", "\n") ;
	std::ranges::sort(employees, std::less{}, &Employee::GetId);
	Print(employees, "Sorted Employees based on ids", "\n") ;

	//Terse, but gives more information to the reader as compared to a for loop
	int cppCount = std::ranges::count(employees, "C++", &Employee::GetProgrammingLanguage);
	std::cout << "Count of C++ programmers:" << cppCount << std::endl;

	//Find if any employee knows Java
	auto itr = std::ranges::find(employees, "Java", &Employee::GetProgrammingLanguage);
	if (itr != employees.end()) {
		std::cout << "Found:" << itr->GetName() << " is a Java programmer" << std::endl;
	}
	auto printer = [](const auto& e) {
		std::cout << e << std::endl;
		};
	//Print all employee names
	std::ranges::for_each(employees,printer , &Employee::GetName);

	std::ranges::for_each(employees, printer, &Employee::GetId);

	//Get ids of all employees that know C++
	auto result = std::ranges::for_each(employees, EmpIds());
	for (int id : result.fun.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}

	auto [last, fnObj] = std::ranges::for_each(employees, EmpIds());
	for (int id : fnObj.m_Ids) {
		std::cout << "Id:" << id << std::endl;
	}
}

int main() {
	UserDefined();
	return 0;
}