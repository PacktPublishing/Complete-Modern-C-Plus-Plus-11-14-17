#include <iostream>

int main() {
	using namespace std;
	int x = 10;
	cout << x << "\n";
	//Always try to initialize pointers to nullptr
	int *ptr = nullptr;
	cout << *ptr << "\n";
	*ptr = 5;
	return 0; 
}