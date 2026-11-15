#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <format>
#include <source_location>

#ifdef LOGGING_ON
inline void Log(const char *message="", const std::source_location &loc = std::source_location::current()) {
	std::cout << std::format("{} <{}><{}>[{}]\n",message, loc.file_name(),loc.line(), loc.function_name());
	
}
#else
inline void Log(const char *message="", const std::source_location &loc = std::source_location::current()) {
	//std::cout << std::format("{} <{}><{}>[{}]\n",message, loc.file_name(),loc.line(), loc.function_name());
}
#endif // LOGGING_ON

#endif // LOGGER_H