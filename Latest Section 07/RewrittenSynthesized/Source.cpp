#include "Integer.h"

int main() {
	std::strong_ordering
	Integer a{ 5 }, b{ 6 };
	std::cout << std::boolalpha;

	std::cout << (a < b) << '\n';
	std::cout << (a > b) << '\n';
	std::cout << (a <= b) << '\n';
	std::cout << (a >= b) << '\n';
	//Rewritten expressions
	auto result = (a <=> b) < 0;
	result = 0 < (b <=> a);

	result = (a <=> b) > 0;
	result = 0 > (b <=> a);

	result = (a <=> b) <= 0;
	result = 0 <= (b <=> a);

	result = (a <=> b) >= 0;
	result = 0 >= (b <=> a);

	std::cout << (6 < b) << '\n';
	std::cout << (8 > b) << '\n';
	std::cout << (6 <= b) << '\n';
	std::cout << (8 >= b) << '\n';

	//Synthesized expressions
	result = 0 < (b <=> 6);
	result = 0 > (b <=> 8);
	result = 0 <= (b <=> 6);
	result = 0 >= (b <=> 8);

	{
		std::cout << (a == b) << '\n';
		std::cout << (a != b) << '\n';

		auto result = (a == b);//(b==a)
		result = !(a == b);//!(b==a)

		std::cout << (6 == b) << '\n';
		std::cout << (8 != b) << '\n';
		result = (b == 6) ;
		result = !(b == 8) ;
	}
}