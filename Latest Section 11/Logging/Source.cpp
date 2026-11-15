#include <iostream>
#include <source_location>
#include <format>
#include "String.h"

class Person {
	String m_Name{};
public:
	Person(const char *pName):m_Name{pName} {
		
	}

};


int main() {
	//Log("Application started");
	Person p1{"Umar"};
	Person p3 = p1;
	p3 = p1;

	Person p2 = std::move(p3);
	p2 = std::move(p1);

	//std::source_location loc {std::source_location::current()} ;
	//std::cout << std::format("<{}><{}>[{}]\n", loc.file_name(),loc.line(), loc.function_name());
}