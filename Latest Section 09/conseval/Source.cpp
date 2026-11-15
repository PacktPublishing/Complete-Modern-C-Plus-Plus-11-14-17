#include <iostream>

consteval int GetNumber() {
	return 42;
}
constexpr int Add(int x, int y) {
	return x + y;
}
constexpr int Max(int x, int y) {
	//Needs C++14 compiler
	//if (x > y)
	//	return x;
	//return y;
	return x > y ? x : y;
}
namespace V1{consteval int Square(int x)
{
	return x * x;
}
constexpr int Cube(int x)
{
	return Square(4) * x ;
}}

constexpr int Square(int x)
{
	return x * x;
}
consteval int Cube(int x)
{
	return Square(x) * x ;
}
int main() {
	int y = 3 ;
	//auto result = Square(y);
	auto val = Cube(3) ;


	//Behaves as a constexpr function
	constexpr int i = GetNumber();
	int arr[i];

	//Behaves as a constexpr function
	const int j = GetNumber();
	int arr1[GetNumber()];

	//Behaves as a normal function
	int x = GetNumber();

	//Error x is not constexpr
	//constexpr int sum = Add(x, 5);

	//Behaves as a normal function. 
	int sum2 = Add(3, 5);

	return 0;
}
/*Constant expression function rules

1. Should accept and return literal types only
 (void, scalar types(int, float, char), references, etc....)
2. Should contain only single line statement that should be a return statement

3. constexpr functions are implicitly inline
*/