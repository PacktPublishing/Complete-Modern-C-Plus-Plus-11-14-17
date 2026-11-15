#include <iostream>
#include <array>
#include <vector>
#include <print>
#include <mdspan>
int main() {
	//int arr[][3] {
	//	{1,2,3},
	//	{4,5,6}
	//};
	//std::cout << "Using built-in array\n";
	//for (std::size_t i = 0 ; i < 2 ; ++i) {
	//	for (std::size_t j = 0; j < 3 ; ++j) {
	//		std::cout << arr[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}
	//std::array<std::array<int,3>,2> a1{
	//	std::array<int,3>{1,2,3},
	//	std::array<int,3>{4,5,6},
	//};
	//std::cout << "Using std::array\n";
	//for (std::size_t i = 0 ; i < a1.size() ; ++i) {
	//	for (std::size_t j = 0; j < a1[i].size() ; ++j) {
	//		std::cout << arr[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}
	//std::cout << "Using std::vector\n";

	//std::vector<std::vector<int>> vec{
	//	{1,2,3},
	//	{4,5,6},
	//};
	//for (std::size_t i = 0 ; i < vec.size() ; ++i) {
	//	for (std::size_t j = 0; j < vec[i].size() ; ++j) {
	//		std::cout << arr[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}

	int arr[]{1,2,3,4,5,6};
	std::mdspan<int,std::extents<std::size_t,2,3>, std::layout_left> m1{arr} ;
	std::println("Rank (dimensions):{}", m1.rank()) ;
	std::println("Rows :{}", m1.extent(0)) ;
	std::println("Columns :{}", m1.extent(1)) ;

	for (std::size_t i = 0 ; i < m1.extent(0) ; ++i) {
		for (std::size_t j = 0; j < m1.extent(1) ; ++j) {
			std::cout << m1[i,j] << ' ';
		}
		std::cout << '\n';
	}

	std::vector vec{10,20,30,40,50,60};
	std::mdspan<int,std::dextents<std::size_t,2>> m2{vec.data(),2,3} ;
	for (std::size_t i = 0 ; i < m2.extent(0) ; ++i) {
		for (std::size_t j = 0; j < m2.extent(1) ; ++j) {
			std::cout << m2[i,j] << ' ';
		}
		std::cout << '\n';
	}

}