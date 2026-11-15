#include <iostream>
#include <string>
#include <thread>

using namespace std::chrono_literals ;

void DoWork(int duration, const std::string &name) {
	for (int i = 0 ; i < duration; ++i) {
		std::cout << name << ' ' ;
		std::this_thread::sleep_for(1s) ;
	}
}
void Task() {
	DoWork(5, "Task") ;
}

int main() {
	std::jthread task{Task} ;
	std::cout << "Thread started\n" ;
	//task.join() ;
}