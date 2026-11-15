#include <iostream>
#include <cassert>
void VerifyPlatform() {
	
}
static_assert(sizeof(void*) == 8, "Only 64-bit platform is supported");

constexpr int Square(int x) {
	return x * x ;
}

template<typename T>
void Use(T a) {
	static_assert(std::is_arithmetic_v<T>, "Not an arithmetic type") ;
}

int main() {
	VerifyPlatform() ;
	auto res = Square(5) ;
	static_assert(res == 25);
	//Use(3) ;
	//Use(1.23) ;
	Use("dfsf") ;
}