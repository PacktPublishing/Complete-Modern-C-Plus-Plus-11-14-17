#pragma once
#include <cstddef>
class String {
	char *m_pBuffer{};
	std::size_t m_Size{};
public:
	String();
	void Allocate(const char* pStr);
	String(const char *pStr);
	String(const String &other) ;
	String& operator=(const String &other) ;
	const char * c_str()const;
	std::size_t size()const;
	void assign(const char *pStr) ;
	~String();
};

