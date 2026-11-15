#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#ifdef LOGGING_ON
#if defined(_MSC_VER)
#define LOG std::cout << "[ " << __FUNCSIG__ << " ]\n"
#elif defined(__GNUC__) || defined(__clang__)
#define LOG std::cout << "[ " << __PRETTY_FUNCTION__ << " ]\n"
#else
#define LOG std::cout << "[ " << __func__ << " ]\n"
#endif

#else
#define LOG void(0)
#endif // LOGGING_ON

#endif // LOGGER_H