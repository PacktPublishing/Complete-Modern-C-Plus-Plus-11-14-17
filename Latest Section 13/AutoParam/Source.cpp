#include <iostream>
#include <format>
namespace Old{template<typename T>
T Square(T a) {
	return a * a ;
}

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b ;
}}

auto Square(auto a) {
	//decltype(a) temp{};
	return a * a ;
}

auto Max(auto a, auto b) {
	return a > b ? a : b ;
}


int main() {
	std::cout << std::format("Result:{}\n", Square(3)) ;
	std::cout << std::format("Result:{}\n", Square(1.3)) ;

	std::cout << std::format("Max:{}\n", Max(3,6.5)) ;
	std::cout << std::format("Max:{}\n", Max(1.3,3)) ;
}