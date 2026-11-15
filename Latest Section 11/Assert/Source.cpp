#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
double Average(int total, int count) {
	assert(count > 0) ;
	return static_cast<double>(total)/count;
}

void Print(int *p) {
	assert(p != nullptr);
	std::cout << *p << '\n';
}

int GetAt(int *pArray, std::size_t size, std::size_t index) {
	assert(pArray != nullptr);
	assert(index < size) ;
	return pArray[index];
}

void UserInput() {
	std::cout << "Enter age:";
	int age{};
	std::cin >> age ;
	if(age > 0) {
		//Use age here
	}else {
		std::cout << "Age must be greater than 0\n";
	}
}

void ReadFile() {
	FILE *fp = fopen("sourc.cpp", "r");
	/*if (fp == nullptr) {
		std::cout << "Could not open file\n";
	}*/
	assert(fp != nullptr);
}
void AllocateBuffer() {
	char *p{};
	assert((p = static_cast<char*>(malloc(100))) != nullptr);
	*p = 'A';
	std::cout << *p ;
	if (p == nullptr) {
		std::cout << "Could not allocate memory\n";
	}
}
int main() {
	/*auto avg = Average(100,10) ;
	int x = 10 ;
	Print(&x) ;
	int arr[5]{1,2,3,4,5} ;
	std::cout << "Element:" << GetAt(arr, 5,3) ;
	UserInput();*/
	//ReadFile();
	AllocateBuffer(); 
}