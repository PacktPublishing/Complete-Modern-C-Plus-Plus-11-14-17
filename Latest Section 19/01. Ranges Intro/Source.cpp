#include <string_view>
#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <list>
#include <forward_list>
template<typename Container>
void Print(Container &container, std::string_view message="", std::string_view sep=" ") {
	std::cout << "##### " << (message.empty() ? "Output" : message) << " #####\n";
	std::cout << "[ " ;
	std::string_view tab="";
	if (sep == "\n") {
		tab="   ";
		std::cout << sep;
	}
	for (auto & e : container) {
		std::cout <<tab<< e << sep ;
	}
	std::cout << "]\n\n";
}

void OldStyle() {
	std::vector<int> data(10) ;
	std::iota(data.begin(), data.end(), 1);
	Print(data, "Vector") ;

	std::random_device rd ;
	std::shuffle(data.begin(), data.end(), rd) ;
	Print(data, "Shuffled") ;

	auto it = std::find(data.begin(), data.end(), 3) ;
	if (it != data.end()) {
		std::cout << "Found\n" ;
	}else {
		std::cout << "Not found\n" ;
	}
	std::sort(data.begin(), data.end()) ;
	Print(data, "Sorted") ;
	
	std::list<int> dest(10);
	auto out = std::copy(data.begin(), data.begin()+6, dest.begin()) ;
	std::vector<int> copied_elements{dest.begin(), out} ;
	Print(copied_elements, "List") ;

	std::for_each(dest.begin(), dest.end(), [](int &x) {
		if (x % 2 != 0) {
			x *= 2 ;
		}
	});

	Print(dest, "Odd doubled") ;

	std::reverse(dest.begin(), dest.end()) ;
	Print(dest, "Reversed") ;
	//std::sort(dest.begin(), dest.end()) ;
	dest.sort() ;
	Print(dest, "Sorted") ;
}
int main() {
	//OldStyle() ;
	//return 0 ;
	std::vector<int> data(10) ;
	std::iota(data.begin(), data.end(), 1);
	Print(data, "Vector") ;

	std::random_device rd ;
	std::ranges::shuffle(data, rd) ;
	Print(data, "Shuffled") ;

	auto it = std::ranges::find(data, 3) ;
	if (it != data.end()) {
		std::cout << "Found\n" ;
	}else {
		std::cout << "Not found\n" ;
	}
	std::ranges::sort(data) ;
	Print(data, "Sorted") ;
	
	std::list<int> dest(10);
	auto result = std::ranges::copy(data.begin(), data.begin()+6, dest.begin()) ;
	//std::vector<int> copied_elements{dest.begin(), result.out} ;
	std::ranges::subrange sub_range{dest.begin(), result.out};
	Print(sub_range, "List") ;

	std::ranges::for_each(dest, [](int &x) {
		if (x % 2 != 0) {
			x *= 2 ;
		}
	});

	Print(dest, "Odd doubled") ;

	std::ranges::reverse(dest) ;
	Print(dest, "Reversed") ;
	//std::ranges::sort(dest) ;


	std::forward_list<int> f{1,2,3,4} ;
	//std::ranges::reverse(f.begin(), f.end()) ;


}