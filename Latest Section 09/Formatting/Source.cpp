#include <iostream>
#include <iomanip>
#include <format>
#include <print>
class Employee
{
public:
    std::string name;
    int id;
    double salary;
    std::string department;
	bool permanent ;
};

void PrintEmployeeOld(const Employee &emp1)
{
    std::cout << std::boolalpha ;
    std::cout 
	<< std::left << std::setw(20) << emp1.name << ' ' 
	<< emp1.id << ' '
	<< std::right << std::fixed << std::setprecision(2) << std::setw(8) << emp1.salary << ' '
	<< std::left <<std::setw(15) << emp1.department << ' '
	<< emp1.permanent 
	<< std::endl;
	
}
void PrintEmployeeFormat(const Employee &emp1)
{
	auto formattedString = std::format("{} {:<20} {:>8.2f} {:<15} {}", 
		emp1.id,
		emp1.name,
		emp1.salary,
		emp1.department,
		emp1.permanent);

    std::cout << formattedString<< std::endl;
	
}
void PrintEmployee(const Employee &emp1)
{
	std::println("{} {:<20} {:>8.2f} {:<15} {}", 
		emp1.id,
		emp1.name,
		emp1.salary,
		emp1.department,
		emp1.permanent);

}

int main() {
    Employee emp1{.name = "John Smith", .id=1010, .salary=85.4560, .department="HR", .permanent=true} ;
    Employee emp2{.name = "Ed Ray", .id=2010, .salary=857.0231, .department="Engineering", .permanent=false} ;
	PrintEmployee(emp1);
	PrintEmployee(emp2);

	return 0;
}