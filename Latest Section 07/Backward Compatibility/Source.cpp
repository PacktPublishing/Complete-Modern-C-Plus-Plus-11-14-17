#include "string.h"
#include <iostream>
#include <utility>
struct Person {
	String m_Name{} ;
	std::strong_ordering operator <=> (const Person&rhs)const = default ;

	/*auto <=> (const Person&rhs)const = default ; {
		if (m_Name == rhs.m_Name) {
			return std::strong_ordering::equal ;
		}
		if (m_Name < rhs.m_Name) {
			return std::strong_ordering::less ;
		}
		return std::strong_ordering::greater ;
	}
	bool operator==(const Person &rhs)const = default; {
		return m_Name == rhs.m_Name ;
	}*/

};
int main() {
	Person s1{"abc"}, s2{"Abc"} ;

	std::cout << std::boolalpha;
	//using namespace std::rel_ops ;
	std::cout << "s1 <  s2 :" << (s1 < s2) << '\n';
	std::cout << "s1 <= s2 :" << (s1 <= s2) << '\n';
	std::cout << "s1 >  s2 :" << (s1 > s2) << '\n';
	std::cout << "s1 >= s2 :" << (s1 >= s2) << '\n';
	std::cout << "s1 == s2 :" << (s1 == s2) << '\n';
	std::cout << "s1 != s2 :" << (s1 != s2) << '\n';

}