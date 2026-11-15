
#include <barrier>
#include <format>
#include <iostream>
#include <latch>
#include <string>
#include <thread>
#include <vector>
using namespace std::chrono_literals ;
void DoWork(int duration, const std::string &name) {
	for (int i = 0 ; i < duration; ++i) {
		std::cout << name << ' ' ;
		std::this_thread::sleep_for(1s) ;
	}
}
constexpr int PHASES = 3 ;
void Worker( int duration, std::string name, std::barrier<void (*)()noexcept> &bar) {
	for (int i = 1 ; i <= PHASES ; ++i) {
		std::cout << std::format("[{} started phase # {}]\n", name, i) ;
		DoWork(duration, name) ;
		std::cout << std::format("\n[{} finished phased # {}]\n", name,i ) ;
		bar.arrive_and_wait() ;
	}
		std::cout << std::format("\n[{} finished its task]\n", name ) ;
	
}
void OnPhaseCompleted()noexcept {
	static int phase = 1 ;
	std::cout << std::format("\n === Phase {} finished === \n", phase++) ;
}
int main() {
	std::vector<std::jthread> threads{} ;
	std::barrier bar{4, OnPhaseCompleted} ;
	threads.emplace_back(Worker, 3, "A", std::ref(bar)) ;
	threads.emplace_back(Worker, 7, "B", std::ref(bar)) ;
	threads.emplace_back(Worker, 4, "C", std::ref(bar)) ;
	threads.emplace_back(Worker, 2, "D", std::ref(bar)) ;
	for (auto &t : threads) {
		t.join() ;
	}
	std::cout << "All tasks have finished\n" ;
	/*std::cout << "Press enter to signal the threads" ;
	std::cin.get() ;
	lt.count_down(4) ;*/
}