#include <iostream>
int main() {
	using namespace std;
	/*int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	for (const auto & x : arr) {
		
		cout << x << " ";
	}*/
	
	//C++20 for with init
	for (int index{}; auto x : { 1,2,3,4 }) {
		cout << index++ << ":" << x << '\n';
	}
	//for(init-clause ; range-declaration : range-expression){
	//	statements
	
	//C++23 alias declaration
	for (typedef unsigned long long ULLONG ; ULLONG x : { 1,2,3,4 }) {
		ULLONG temp{} ;
		cout << x << '\n';
	}
	return 0;
}