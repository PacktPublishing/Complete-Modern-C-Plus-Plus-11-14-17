#include <cstddef>
#include <iostream>
#include <cassert>
class Grid {
	int m_Data[3][3]{};
public:
	std::size_t Rows()const {
		return 3;
	}
	std::size_t Columns()const {
		return 3;
	}
	int * operator [](std::size_t row) {
		return m_Data[row] ;
	}
	int & operator[](std::size_t row, std::size_t column) {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
	const int & operator[](std::size_t row, std::size_t column)const {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
	int & GetAt(std::size_t row, std::size_t column) {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
	const int & GetAt(std::size_t row, std::size_t column)const {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
	int & operator()(std::size_t row, std::size_t column) {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
	const int & operator()(std::size_t row, std::size_t column)const {
		assert(row < 3 && column  < 3) ;
		return m_Data[row][column];
	}
};

int main() {
	Grid grid{} ;
	/*for (std::size_t i = 0; i < grid.Rows(); ++i) {
		for (std::size_t j = 0; j < grid.Columns(); ++j) {
			grid.GetAt(i,j) = i * grid.Columns() + j;
		}
	}
	for (std::size_t i = 0; i < grid.Rows(); ++i) {
		for (std::size_t j = 0; j < grid.Columns(); ++j) {
			std::cout << grid.GetAt(i,j)  << ' ';
		}
		std::cout << '\n';
	}*/
	for (std::size_t i = 0; i < grid.Rows(); ++i) {
		for (std::size_t j = 0; j < grid.Columns(); ++j) {
			grid[i,j] = i * grid.Columns() + j;
		}
	}
	for (std::size_t i = 0; i < grid.Rows(); ++i) {
		for (std::size_t j = 0; j < grid.Columns(); ++j) {
			std::cout << grid[i,j]  << ' ';
		}
		std::cout << '\n';
	}
}

