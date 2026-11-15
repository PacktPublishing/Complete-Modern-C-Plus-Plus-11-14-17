#include <iostream>
struct Unnamed {
	template<typename T1, typename T2>
	auto operator()(T1 x, T2 y)const {
		return x + y;
	}
	template<typename T1, typename T2>
	static auto Internal(T1 x,T2 y) {
		return Unnamed{}(x,y) ;
	}
	typedef int (*Fn)(int,int) ;
	operator Fn()const {
		return Internal;
	}

	typedef float (*Fn_float)(float,float) ;
	operator Fn_float()const {
		return Internal;
	}
};

int main() {
	
	auto sum = [](auto x, auto y){
		return x + y;			
	};
	Unnamed n;
	int (*p1)(int,int) = sum ;
	float(*p2)(float, float) = sum ;
	p1 = n ;
	std::cout << "Sum is:" << sum(5, 2.5) << std::endl;
	std::cout << "Sum is:" << sum(5.4, 2.2) << std::endl;
	std::cout << "end of main()\n";
	return 0;
}