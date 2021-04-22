#include <iostream>

#include "func.h"

int main() {
	using namespace std;
	int result = Add(3, 5);
	cout << result << endl;
	Add(3.1, 6.2);
	int x = 1;
	Print(&x);// Print
	return 0;
}
