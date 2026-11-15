#include <iostream>
struct Unnamed {
	int operator()(int x, int y)const {
		return x + y;
	}
	static int Internal(int x,int y) {
		return Unnamed{}(x,y) ;
	}
	typedef int (*Fn)(int,int) ;
	operator Fn()const {
		return Internal;
	}
};
void AtExitHandler() {
	std::cout << "Called after main()\n";
}
struct AtExit {
	void operator()()const {
		std::cout << "Called after main()\n";
	}
	static void Internal() {
		return AtExit{}() ;
	}
	typedef void (*Fn)() ;
	operator Fn()const {
		return Internal;
	}
};
int main() {
	AtExit handler{};
	std::atexit(handler) ;
	auto fn = []() {
		std::cout << "Welcome to Lambda expressions" << std::endl ;
	};
	fn();
	void (*p)() = handler;
	p = fn ;
	std::cout << typeid(fn).name() << std::endl;
	auto sum = [](int x, int y){
		return x + y;			
	};
	Unnamed n;
	int (*p1)(int,int) = sum ;
	p1 = n ;
	std::cout << "Sum is:" << sum(5, 2) << std::endl;
	std::cout << "end of main()\n";
	return 0;
}