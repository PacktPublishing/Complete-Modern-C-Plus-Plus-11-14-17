/* Operators that are static 
 * new/delete (ALWAYS)
 * operator() (OPTIONAL)
 * operator[] (OPTIONAL)
 */
#include <cstddef>
#include <iostream>
#include <cassert>
struct IsEven {
	//int data{2};
	bool Check(int x)const {
		return x % 2 == 0 ;
	}
	static bool operator()(int x) {
		return x % 2 == 0 ;
	}
};

namespace Old{
	class Months {
	public:
		static const char * operator[](std::size_t month) {
			switch (month) {
			case 1:  return "January";
			case 2:  return "February";
			case 3:  return "March";
			case 4:  return "April";
			case 5:  return "May";
			case 6:  return "June";
			case 7:  return "July";
			case 8:  return "August";
			case 9:  return "September";
			case 10: return "October";
			case 11: return "November";
			case 12: return "December";
			default: return "Invalid month";
			}
		}
	};
}

class Months {
	inline static const char* m_Names[12]
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
public:
	static const char * operator[](std::size_t month) {
		assert(month >=1 && month <=12) ;
		return m_Names[month-1];
	}
};

int main() {
	IsEven obj{} ;
	obj.Check(5) ;

	obj(5);

	Months m;
	std::cout << m[2] << '\n';
}

