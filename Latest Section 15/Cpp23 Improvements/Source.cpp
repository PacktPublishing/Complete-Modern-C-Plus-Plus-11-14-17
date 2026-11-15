#include <print>
#include <iostream>
int main() {
	/*auto separator = []()static {
		std::println("-------------------------");
	};
	separator() ;*/

	auto fibonacci = [](auto &&self, int n) {
		if (n <= 1) {
			return n ;
		}
		return self(self, n-1) + self(self, n-2) ;
	};
	for (int i = 0 ; i < 10 ; ++i) {
		std::cout << fibonacci(fibonacci, i) << ' ';
	}
}