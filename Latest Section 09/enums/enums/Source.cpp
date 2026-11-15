#include <iostream>
enum class Color : long{RED=5, GREEN, BLUE} ;
void FillColor(Color color) {
	using enum Color; //Requires C++20
	//Fill background with some color
	if(color == RED) {
		//Paint with red color
		std::cout << "RED" << std::endl; 
	}
	else if(color == GREEN) {
		//Paint with green color
		std::cout << "GREEN" << std::endl; 
	}
	else if(color == BLUE) {
		//Paint with blue color
		std::cout << "BLUE" << std::endl; 
	}
}
enum class TrafficLight : char{RED='c', GREEN, YELLOW} ;
int main() {
	using enum Color ;//Requires C++20
	//using enum TrafficLight ;
	Color c = RED ;
	FillColor(c) ;
	FillColor(GREEN) ;
	FillColor(static_cast<Color>(2)) ;
	int x = static_cast<int>(Color::RED) ;
	return 0;
}