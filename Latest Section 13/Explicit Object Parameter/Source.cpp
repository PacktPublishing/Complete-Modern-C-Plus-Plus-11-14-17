#include <utility>
#include <print>
#include "logger.h"
#include "string.h"
template<typename T>
class Box {
	T m_Type{} ;
public:
	Box()=default;

	template<typename U>
	requires (!std::same_as<std::remove_cvref_t<U>, Box>)
	Box(U &&t):m_Type{std::forward<U>(t)} {
		
	}
	void getObj(this Box &self) {
		
	}
	/*template<typename Self>
	auto&& get(this Self &&self) {
		Logger::Log();
		return std::forward<Self>(self).m_Type;
	}*/

	auto&& get(this auto &&self) {
		Logger::Log();
		return std::forward_like<decltype(self)>(self.m_Type);
		return std::forward<decltype(self)>(self).m_Type;
	}
	/*T& get(this Box &self) {
		Logger::Log();
		return self.m_Type;
	}
	const T& get(this const Box &self) {
		Logger::Log();
		return self.m_Type;
	}
	T&& get(this Box &&self) {
		Logger::Log();
		return std::move(self.m_Type);
	}
	const T&& get(this const Box &&self) {
		Logger::Log();
		return std::move(self.m_Type);
	}*/

	/*T& get()& {
		Logger::Log();
		return m_Type;
	}
	const T& get()const & {
		Logger::Log();
		return m_Type;
	}
	T&& get()&& {
		Logger::Log();
		return std::move(m_Type);
	}
	const T&& get()const && {
		Logger::Log();
		return std::move(m_Type);
	}*/
};

int main() {
	std::println("Non-const Box");
	Box<String> b1{"Hello"};
	String &s1 = b1.get() ;

	std::println("Constant Box");
	const Box<String> b2{"Hello"} ;
	const String &s2 = b2.get() ;

	std::println("Temporary Box (rvalue)");
	String s3 = Box<String>{"Hello"}.get();
}