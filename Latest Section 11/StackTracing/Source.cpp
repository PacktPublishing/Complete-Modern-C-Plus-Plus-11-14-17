#include <iostream>
#include <format>
#include <vector>
#include <expected>
#include <stacktrace>
#define LOGGING_ON
#include "logger.h"


std::expected<std::string, std::string> GetUser(std::size_t index) {
	static std::vector<std::string> users{
		"Will",
		"Joe",
		"Bob",
		"Alice",
		"John"
	};
	
	try {
		return users.at(index);
	} catch (const std::exception& ex) {
		//Log("EXCEPTION => ");
		std::cout << std::format("--- STACK TRACE ---\n") ;
		//std::cout << std::stacktrace::current() << '\n' ;
		for (const std::stacktrace_entry &ste : std::stacktrace::current()) {
			std::cout << std::format("<{}> {} [{}]\n", ste.source_line(), ste.source_file(), ste.description());
		}
		return std::unexpected{ ex.what() };
	}
}

std::expected<std::string, std::string> LoadUser(std::size_t index) {
	std::cout << std::format("Loading user # {}\n", index);
	return GetUser(index);
}

void Input() {
	std::cout << "Enter index: ";
	std::size_t index{};
	std::cin >> index;
	auto user = LoadUser(index);
	if (user) {
		std::cout << *user << '\n';
	} else {
		std::cout << std::format("\n### Error: {} ###\n", user.error());
	}
}

int main() {
	Input();
}