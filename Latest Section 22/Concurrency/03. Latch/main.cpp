
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
void Worker( int duration, std::string name, std::latch &lt) {
	std::cout << std::format("[{} started initialization]\n", name) ;
	DoWork(duration, name) ;
	std::cout << std::format("\n[{} finished initialization]\n", name) ;
	//lt.wait() ;
	lt.arrive_and_wait() ;
	DoWork(1000, std::format("^{}^ ",name)) ;

}
int main() {
	std::vector<std::jthread> threads{} ;
	std::latch lt{4} ;
	threads.emplace_back(Worker, 3, "A", std::ref(lt)) ;
	threads.emplace_back(Worker, 7, "B", std::ref(lt)) ;
	threads.emplace_back(Worker, 4, "C", std::ref(lt)) ;
	threads.emplace_back(Worker, 2, "D", std::ref(lt)) ;
	/*std::cout << "Press enter to signal the threads" ;
	std::cin.get() ;
	lt.count_down(4) ;*/
}