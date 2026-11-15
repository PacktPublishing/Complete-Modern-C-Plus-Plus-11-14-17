#include "Integer.h"
struct Type {
	int value{};
	char array[8]{};
	int* ptr{};
	auto operator <=>(const Type& rhs)const = default;
};
struct Outer {
	Type t ;
	int member ;
	auto operator <=>(const Outer& rhs)const = default;
};

int main() {
	int x = 10;
	int *p1 = new int{3} ;
	int *p2 = new int{3} ;
	Outer a{ .t = {.value = 1, .array = {"abc"}, .ptr = &x}, .member=10 };
	Outer b{ .t = {.value = 1, .array = {"abc"}, .ptr = &x}, .member=10 };
	std::cout << std::boolalpha ;
	std::cout << (a == b) << '\n';
	std::cout << (a != b) << '\n';
	std::cout << (a < b) << '\n';
	std::cout << (a > b) << '\n';
	std::cout << (a <= b) << '\n';
	std::cout << (a >= b) << '\n';
	return 0;
	{
		Integer a{ 5 }, b{ 6 };
		std::cout << std::boolalpha;
		std::cout << (a == b) << '\n';
		std::cout << (a != b) << '\n';
		std::cout << (a < b) << '\n';
		std::cout << (a > b) << '\n';
		std::cout << (a <= b) << '\n';
		std::cout << (a >= b) << '\n';

		std::cout << (a == 6) << '\n';
		std::cout << (6 == b) << '\n';

		auto result = (a <=> b) < 0;
		result = (a <=> b) > 0;
		result = (a <=> b) <= 0;
		result = (a <=> b) >= 0;
	}

}