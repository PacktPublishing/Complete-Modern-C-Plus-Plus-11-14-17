#include <iostream>

#include "String.h"

const char * TextInput(const char *pMsg) {
	std::cout << pMsg ;
	const int INPUT_SIZE=32;
	char *pText = new char[INPUT_SIZE]{};
	std::cin.getline(pText, INPUT_SIZE) ;
	return pText;
}
void OldCode() {
		/*std::cout << "Name?" ;
	char name[10]{};
	std::cin.getline(name, 10) ;
	std::cout << "Department?";
	char dept[10]{};
	std::cin.getline(dept, 10) ;
	std::cout << "Company?";
	char company[20]{};
	std::cin.getline(company, 20) ;*/
	auto name = TextInput("Name?");
	delete []name;
	auto dept = TextInput("Dept?");
	delete []dept;
	auto company = TextInput("Company?");
	delete []company;
	std::cout << "You are " << name << " & you work in " << dept << " at " << company << '\n' ;
}

void Print(String s1) {
	std::cout << s1.c_str() << '\n';
	std::cout << s1.size() << '\n';
}

String Create(const char *pStr) {
	if (pStr == nullptr) {
		return {};
	}
	//String str{pStr} ;
	//return str;//Named return value optimization (NRVO)
	return String{pStr};//RVO
}
int main() {
	//_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	//String s1 = Create("Hello world");
	//s1.assign("Goodbye world") ;
	//s1 = s1 ;
	//Print(s1);
	Print("Umar");
	//String s2{"Umar"} ;
	//String s3 = "Umar";//elided

}