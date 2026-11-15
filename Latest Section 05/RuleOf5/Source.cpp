#include <iostream>

#include "String.h"

class Person {
	String m_Name{};
public:
	Person(const char *pName):m_Name{pName} {
		
	}
	//~Person()=default;
	//Person(const Person &)=default;
	//Person& operator=(const Person &)=default;

	//Person(Person&&)=default;
	Person& operator=(Person &&)=default;
};

int main() {
	Person p1{"Umar"};
	//Person p3 = p1;
	//p3 = p1;

	Person p2 = std::move(p1);
	p2 = std::move(p1);
}