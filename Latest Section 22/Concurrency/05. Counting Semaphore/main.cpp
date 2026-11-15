
#include <barrier>
#include <format>
#include <iostream>
#include <latch>
#include <string>
#include <thread>
#include <vector>
#include <semaphore>
using namespace std::chrono_literals;
void DoWork(int duration, const std::string& name) {
	for (int i = 0; i < duration; ++i) {
		std::cout << name << ' ';
		std::this_thread::sleep_for(1s);
	}
}
//std::counting_semaphore sem{1}  ;
std::binary_semaphore sem{1} ;
void Worker(int duration, std::string name) {
	sem.acquire() ;
		std::cout << std::format("[{} opened a connection]\n", name);
		DoWork(duration, name);
		std::cout << std::format("\n[{} closed the connection]\n", name);
	sem.release() ;
}

int main() {
	std::vector<std::jthread> threads{};
	threads.emplace_back(Worker, 3, "A");
	threads.emplace_back(Worker, 7, "B");
	threads.emplace_back(Worker, 4, "C");
	threads.emplace_back(Worker, 2, "D");
	threads.emplace_back(Worker, 5, "E");
	threads.emplace_back(Worker, 6, "F");
	for (auto& t : threads) {
		t.join();
	}
	std::cout << "All tasks have finished\n";

}