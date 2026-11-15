#include <iostream>
#include <string>
#include <thread>

using namespace std::chrono_literals ;

void Task(std::stop_token st) {
	//DoWork(5, "Task") ;
	while (true) {
		std::cout << "." ;
		std::this_thread::sleep_for(1s) ;
		if (st.stop_requested()) {
			std::cout << "Thread received stop signal!\n" ;
			return ;
		}
	}
}

int main() {
	std::jthread task{Task} ;
	std::cout << "Thread started\n" ;
	std::cout << "Press enter to send stop signal" ;
	std::cin.get() ;
	task.request_stop() ;
	std::cout << "main finished\n" ;
}