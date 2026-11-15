#pragma once
#include <cstddef>
#include <cstring>
#define LOGGING_ON
#include "logger.h"
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
	bool operator ==(const String &rhs)const {
		LOG ;
		if (m_Size != rhs.m_Size) {
			return false;
		}
		return strcmp(m_pBuffer, rhs.m_pBuffer) == 0 ;
	}
	bool operator < (const String &rhs)const {
		LOG ;
		return strcmp(m_pBuffer, rhs.m_pBuffer) < 0;
	}
};

