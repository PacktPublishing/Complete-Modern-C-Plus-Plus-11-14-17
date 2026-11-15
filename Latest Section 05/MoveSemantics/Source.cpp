#include <iostream>

#include "String.h"


String Create(const char *pStr) {
	if (pStr == nullptr) {
		return {};
	}
	String str{pStr} ;
	return str;
}
String & Modify(String &obj, const char *p) {
	obj.assign(p);
	return obj;
}

void Print(const String &) {
	std::cout << "lvalue\n";
}
void Print(String &&s) {
	String copy{s};
	std::cout << "rvalue\n";
}
int main() {
	String s1 {"Hello world"};
	//String s2{std::move(s1)};
	String s2{} ;
	s2 = std::move_if_noexcept(s1) ;
	//std::cout << s1.c_str() << '\n';
	s1.assign("Goodbye world");
	//Print(s1) ;
	//Print("Hello") ;
	//Print(Create("Hello"));
	//Print(Modify(s1, "Goodbye"));
}