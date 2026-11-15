#include <string>
#include <iostream>
#include <print>
#include <vector>
#include <flat_set>
#include <set>
#include "p_benchmark.h"

constexpr std::size_t SIZE = 1000;
std::set<std::size_t> s{};
std::flat_set<std::size_t> fs{};

_declspec(noinline)
void SetInsertion() {
	for (std::size_t i = SIZE; i > 0; --i) {
		s.insert(i);
	}
}
_declspec(noinline)
void FlatSetInsert() {
	for (std::size_t i = SIZE; i > 0; --i) {
		fs.insert(i);
	}
}

_declspec(noinline)
void SetLookup() {
	auto it = s.find(SIZE + 1);
	if (it != s.end()) {
		std::println("Found");
	}
}
_declspec(noinline)
void FlatSetLookup() {
	auto it = fs.find(SIZE + 1);
	if (it != fs.end()) {
		std::println("Found");
	}
}
int main() {
	Benchmark<std::chrono::nanoseconds>(SetInsertion, "set Insertion");
	Benchmark<std::chrono::nanoseconds>(FlatSetInsert, "flat_set insertion");
	Benchmark<std::chrono::nanoseconds>(SetLookup, "set lookup");
	Benchmark<std::chrono::nanoseconds>(FlatSetLookup, "flat_set lookup");
}

