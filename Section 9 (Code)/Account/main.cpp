#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transaction.h"
#include <typeinfo>
int main()
{
	Savings ch("Bob", 100, 50);
	try {
		Transact(ch);
	}catch(std::exception &ex) {
		std::cout << "Exception:" << ex.what() << '\n' ;
	}

    return 0;
}
 
