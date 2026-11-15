#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <format>
#include <source_location>

class Logger {
private:
	inline static bool s_Enabled = true;

public:
	static void Log(
		std::string_view message = "",
		const std::source_location& loc = std::source_location::current()) {
		if (!s_Enabled)
			return;

		std::cout << std::format(
			"{:<{}} [{}]\n",
			message, (message.empty() ? 0 :message.size() + 2),
			loc.function_name());
	}

	static void Disable() {
		s_Enabled = false;
	}
	static void Enable() {
		s_Enabled = true;
	}
};
#endif // LOGGER_H