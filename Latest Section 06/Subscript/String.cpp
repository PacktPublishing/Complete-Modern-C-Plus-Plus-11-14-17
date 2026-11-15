#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <cstring>
#include <cassert>
#define LOGGING_ON
#include "logger.h"
String::String() {
	m_pBuffer = new char[1]{'\0'};
	LOG;
}

void String::Allocate(const char* pStr) {
	m_Size    = strlen(pStr) ;
	m_pBuffer = new char[m_Size + 1];
	strcpy(m_pBuffer, pStr) ;
}

String::String(const char* pStr) {
	LOG;
	Allocate(pStr);
}

String::String(const String& other) {
	LOG;
	Allocate(other.c_str());
}
String::String(String&& other) {
	LOG;
	m_Size = other.m_Size ;
	m_pBuffer = other.m_pBuffer ;

	other.m_Size = 0 ;
	other.m_pBuffer = nullptr;
}
String& String::operator=(const String& other) {
	LOG;
	if (this != &other) {
		assign(other.c_str());
	}
	return *this;
}

String& String::operator=(String&& other) {
	LOG;
	if (this != &other) {
		m_Size = other.m_Size;
		m_pBuffer = other.m_pBuffer;

		other.m_Size = 0;
		other.m_pBuffer = nullptr;
	}
	return *this;
}

const char* String::c_str() const {
	return m_pBuffer ;
}
std::size_t String::size() const {
	return m_Size ;
}
void String::assign(const char* pStr) {
	delete []m_pBuffer;
	Allocate(pStr);
}

char& String::at(std::size_t index) {
	assert(index < m_Size) ;
	return m_pBuffer[index];
}

const char& String::at(std::size_t index) const {
	assert(index < m_Size) ;
	return m_pBuffer[index];
}

char& String::operator[](std::size_t index) {
	return m_pBuffer[index];
}

const char& String::operator[](std::size_t index) const {
	return m_pBuffer[index];
}

String::~String() {
	LOG;
	delete []m_pBuffer;
}
