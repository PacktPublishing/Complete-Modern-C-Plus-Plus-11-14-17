//This is a single line comment

/*
This is a 
multi line comment
*/

/*
iostream contains the classes & objects for input & output
*/
#include <iostream>

//Entry point for all C & C++ programs
int main() {
	/*
	std is a region in which types are declared, so that
	they are not visible directly, unless opened with the 
	using declarative
	*/
	using namespace std;
	cout << "Hello "  <<  "C++" << endl;

	//Return exit code to the operating system
	return 0;
}