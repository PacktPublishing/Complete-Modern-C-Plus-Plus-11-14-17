#include "string.h"
#include <iostream>
#include <utility>
int main() {
	String s1{"abc"}, s2{"abc"} ;
	bool result{} ;
	//std::cout << std::format("s1 <  s2 :{}\n", s1 < s2  );
	//std::cout << std::format("s1 <= s2 :{}\n", s1 <= s2 );
	//std::cout << std::format("s1 >  s2 :{}\n", s1 > s2  );
	//std::cout << std::format("s1 >= s2 :{}\n", s1 >= s2 );
	//std::cout << std::format("s1 == s2 :{}\n", s1 == s2 );
	//std::cout << std::format("s1 != s2 :{}\n", s1 != s2 );

	std::cout << std::boolalpha;
	//using namespace std::rel_ops ;
	std::cout << "s1 <  s2 :" << (s1 < s2) << '\n';
	std::cout << "s1 <= s2 :" << (s1 <= s2) << '\n';
	std::cout << "s1 >  s2 :" << (s1 > s2) << '\n';
	std::cout << "s1 >= s2 :" << (s1 >= s2) << '\n';
	std::cout << "s1 == s2 :" << (s1 == s2) << '\n';
	std::cout << "s1 != s2 :" << (s1 != s2) << '\n';

}