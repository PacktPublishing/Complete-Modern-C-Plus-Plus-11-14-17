#include "string.h"
#include <iostream>
#include <format>
int main() {
	String s1{"abc"}, s2{"abc"} ;
	bool result{} ;
	std::cout << std::format("s1 <  s2 :{}\n", s1 < s2  );
	std::cout << std::format("s1 <= s2 :{}\n", s1 <= s2 );
	std::cout << std::format("s1 >  s2 :{}\n", s1 > s2  );
	std::cout << std::format("s1 >= s2 :{}\n", s1 >= s2 );
	std::cout << std::format("s1 == s2 :{}\n", s1 == s2 );
	std::cout << std::format("s1 != s2 :{}\n", s1 != s2 );

}