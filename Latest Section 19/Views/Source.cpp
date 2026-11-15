#include <string_view>
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <ranges>
template<std::ranges::range Container>
void Print(Container &&container, std::string_view message="", std::string_view sep=" ") {
	std::cout << "##### " << (message.empty() ? "Output" : message) << " #####\n";
	std::cout << "[ " ;
	std::string_view tab="";
	if (sep == "\n") {
		tab="   ";
		std::cout << sep;
	}
	for (auto && e : container) {
		std::cout <<tab<< e << sep ;
	}
	std::cout << "]\n\n";
}

int main() {
	//std::vector<int> data(10) ;
	//std::iota(data.begin(), data.end(), 1);
	auto data = std::views::iota(1,10) ;
	Print(data, "Iota (1-10)") ;

	//auto take_5 = std::views::take(data, 5) ;
	//Print(take_5, "Take 5") ;

	//auto takewhile_5 = std::views::take_while(data, [](int x) {
	//	return x < 5 ;
	//}) ;
	//Print(takewhile_5, "Take While < 5") ;

	//auto drop = std::views::drop(data, 7) ;
	//Print(drop, "Drop upto 7 (inclusive)") ;

	//auto odd = std::views::filter(data, [](int x) {
	//	return x % 2 != 0 ;
	//});
	////Print(odd, "Odd") ;

	//auto transform = std::views::transform(odd, [](int x) {
	//	return x*=2 ;
	//});
	//Print(transform, "Odd x2") ;

	//Print(data, "Iota (1-10)") ;


	/*Print(std::views::transform(std::views::filter(data, [](int x) {
		return x % 2 != 0;
		}), [](int x) {
			return x *= 2;
			}), "Odd x2");*/

	Print(data
		| std::views::filter([](int x) {
			return x % 2 != 0;
			})
		| std::views::transform([](int x) {
			return x *= 2;
			}));

}