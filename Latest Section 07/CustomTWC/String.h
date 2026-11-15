#pragma once
#include <cstddef>
#include <compare>
#include <cstring>
class String {
	char* m_pBuffer{};
	std::size_t m_Size{};
public:
	String();
	void Allocate(const char* pStr);
	String(const char* pStr);
	String(const String& other);
	String(String&& other)noexcept;
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	const char* c_str()const;
	std::size_t size()const;
	void assign(const char* pStr);
	char& at(std::size_t index);
	const char& at(std::size_t index)const;
	~String();
	auto operator <=>(const String& rhs)const {
		auto result = strcmp(m_pBuffer, rhs.m_pBuffer);
		if (result < 0) {
			return std::strong_ordering::less;
		}
		if (result > 0) {
			return std::strong_ordering::greater;
		}
		return std::strong_ordering::equal;
	}
	bool operator ==(const String &rhs)const {
		if (m_Size != rhs.m_Size) {
			return false;
		}
		return strcmp(m_pBuffer, rhs.m_pBuffer) == 0 ;
	}
};

