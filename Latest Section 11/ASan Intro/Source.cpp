#include <iostream>

void Print(int *p, std::size_t size) {
	for (std::size_t i = 0; i <= size ; ++i) {
		std::cout << p[i] << ' ' ;
	}
}

int main() {
	//int arr[]{4,1,6,2,9};
	int *arr = new int[]{4,1,6,2,9};
	delete []arr;
	Print(arr,5 /*std::size(arr)*/);
}