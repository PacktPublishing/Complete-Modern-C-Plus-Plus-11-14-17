#ifndef P_BENCHMARK_H
#define P_BENCHMARK_H
#include <chrono>
#include <iostream>

template <typename Duration, typename Func, typename... Args>
void Benchmark(Func&& func, std::string_view message = "", Args&&... args) {

	auto duration_to_string = [](auto duration)constexpr {
		if constexpr (std::is_same_v<decltype(duration), std::chrono::nanoseconds>) {
			return " nanoseconds";
		}
		else if constexpr (std::is_same_v<decltype(duration), std::chrono::microseconds>) {
			return " microseconds";
		}
		else if constexpr (std::is_same_v<decltype(duration), std::chrono::milliseconds>) {
			return " milliseconds";
		}
		else if constexpr (std::is_same_v<decltype(duration), std::chrono::seconds>) {
			return " seconds";
		}
		else if constexpr (std::is_same_v<decltype(duration), std::chrono::minutes>) {
			return " minutes";
		}
		else if constexpr (std::is_same_v<decltype(duration), std::chrono::hours>) {
			return " hours";
		}
		else {
			return "unknown duration type";

		}
		};

	auto start = std::chrono::high_resolution_clock::now();

	std::forward<Func>(func)(std::forward<Args>(args)...);

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<Duration>(end - start);
	if (!message.empty()) {
		std::cout << "====== " << message << " ======\n";

	}
	std::cout << "Execution time: " << duration.count() << duration_to_string(duration) << '\n';
	std::cout << "-\n";
}

#endif // P_BENCHMARK_H