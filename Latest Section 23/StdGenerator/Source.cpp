#include <iostream>
#include <generator>
void Numbers1() {
	for (int i = 0 ; i < 10 ; ++i) {
		std::cout << i << ' ';
	}
}

int Numbers() {
	static int i = 0;
	return i++;
}

std::generator<int> CoNumbers(int start, int end, int step=1) {
	for (int i = start ; i < end ; i += step) {
		co_yield i;
	}
}

int main() {
	for (auto a : CoNumbers(10, 20, 2)) {
		std::cout << a << ' ' ;
	}
}