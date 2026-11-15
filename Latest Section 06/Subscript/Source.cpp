#include <iostream>

#include "String.h"



int main() {
	String s1 {"Hello world"};
	//char ch = s1.at(100) ;
	//s1.at(0) = 'h';
	char ch = s1[100] ;
	s1[0] = 'h';
	std::cout << s1.c_str() << '\n';
}