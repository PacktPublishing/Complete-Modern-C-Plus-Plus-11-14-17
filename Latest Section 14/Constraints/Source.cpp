
#include <iostream>
#include <type_traits>
#include <format>
#include <concepts>
namespace Old {
	template<typename T, std::enable_if_t<std::is_floating_point_v<T>, T> = 0>
	T Divide(T a, T b) {
		//static_assert(std::is_floating_point<T>::value, "Only floating point type supported");
		/*if(std::is_floating_point<T>::value == false) {
			std::cout << "Use floating point types only\n" ;
			return 0 ;
		}*/
		return a / b;
	}
	template<typename T, std::enable_if_t<std::is_integral_v<T>, T> = 0>
	void Process(T a) {
		std::cout << std::format("Processing integral type:{}\n", a);
	}
	template<typename T, std::enable_if_t<std::is_floating_point_v<T>, T> = 0>
	void Process(T a) {
		std::cout << std::format("Processing floating-point type:{}\n", a);
	}
}
template<typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template<typename T>
requires std::floating_point<T>
T Divide(T a, T b) {
	return a / b;
}

//Requires clause
template<typename T>
requires std::floating_point<T>
T Divide1(T a, T b) {
	return a / b;
}

//Trailing requires clause
template<typename T>
T Divide2(T a, T b) requires std::floating_point<T>{
	return a / b;
}

//Constrained template parameter
template<std::floating_point T>
T Divide3(T a, T b) {
	return a / b;
}

//Constrained auto parameter
auto Divide4(std::floating_point auto a, std::floating_point auto b) {
	return a / b;
}

template<typename T>
void Print(T a, T b) {
	
}

void Print(auto a, auto b) {//T1 a, T2 b
	
}

template<typename T>
requires std::integral<T>
void Process(T a) {
	std::cout << std::format("Processing integral type:{}\n", a);
}
template<typename T>
requires std::floating_point<T>
void Process(T a) {
	std::cout << std::format("Processing floating-point type:{}\n", a);
}


int main() {
	std::cout << Divide(5.1, 7.3) << '\n';
	std::cout << Divide(5.1f, 7.3f) << '\n';
	//std::cout << Divide(5, 7) << '\n';

	Process(3);
	Process(1.2);

}