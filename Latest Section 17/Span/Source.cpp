#include <array>
#include <vector>
#include <iostream>
#include <span>
void Print(int *p, std::size_t size) {
	for (std::size_t i = 0 ; i < size ; ++i) {
		std::cout << p[i] << ' ';
	}
	std::cout << '\n';
}

void Print(std::array<int, 5> arr) {
	for (std::size_t i = 0 ; i < arr.size() ; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void Print(std::vector<int> &arr) {
	for (std::size_t i = 0 ; i < arr.size() ; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void Print(std::span<const int> arr) {
	//arr[0] = 100 ;
	for (std::size_t i = 0 ; i < arr.size() ; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
int main() {
	int arr1[]{1,2,3,4,5};
	Print(arr1, 5);

	std::array arr2{1,2,3,4,5};
	Print(arr2);

	std::vector vec1{1,2,3,4,5};
	Print(vec1);
	std::cout << "Using span\n" ;
	std::span<int,5> s1{arr1};
	std::span<int> s2{arr2.begin(),3} ;
	std::span<int> s3{vec1.data(),3} ;
	//std::span<const int> s4{std::vector{100,200,300}};
	//Print(s4) ;
	auto list = {10,20,30};
	Print(arr1) ;
	Print(s2) ;
	vec1.push_back(10) ;
	s3 = std::span<int>{vec1} ;
	Print(s3) ;
	Print(list) ;

}