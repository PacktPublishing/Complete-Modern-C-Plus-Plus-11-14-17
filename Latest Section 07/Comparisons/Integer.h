#pragma once
#include <iostream>
class Integer {
	int m_Value{};
public:
	Integer() = default;
	Integer(int value) :m_Value{ value } {}
	int GetValue() const {
		return m_Value;
	}
	void SetValue(int value) {
		m_Value = value;
	}
	auto operator <=>(const Integer &)const = default;
	/*friend bool operator ==(const Integer &x, const Integer& a) ;
	
	friend std::ostream& operator <<(std::ostream& out, const Integer& a) {
		return out << a.m_Value;
	}*/
};
//bool operator ==(const Integer &x, const Integer& a) {
//		return x.m_Value == a.m_Value;
//	}
//	bool operator !=(const Integer &x,const Integer& a) {
//		return !(x == a);
//	}