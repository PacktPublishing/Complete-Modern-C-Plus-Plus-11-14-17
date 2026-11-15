#include <coroutine>
#include <iostream>
#define LOGGING_ON
#ifdef LOGGING_ON
#define LOG std::cout << __func__ << '\n'
#else
#define LOG ((void)0)
#endif

class Task {
public:
	struct promise_type {
		promise_type() {
			LOG;
		}
		~promise_type() {
			LOG;
		}
		Task get_return_object() {
			LOG;
			auto handle = std::coroutine_handle<promise_type>::from_promise(*this) ;
			return {handle};
		}
		std::suspend_never initial_suspend() {
			std::cout << __func__ << '\n';
			return {};
		}
		std::suspend_never final_suspend()noexcept {
			std::cout << __func__ << '\n';
			return {};
		}
		void unhandled_exception() {
			
		}
		void return_void() {
			std::cout << __func__ << '\n';
			
		}
	};
	void Resume() {
		if (m_Handle && !m_Handle.done()) {
			m_Handle.resume() ;
		}
	}
	Task(const std::coroutine_handle<promise_type> &handle):m_Handle{handle} {
		LOG;
	}
	~Task() {
		LOG;
		if (m_Handle) {
			//m_Handle.destroy();
		}
	}
private:
	std::coroutine_handle<promise_type> m_Handle{} ;

};

Task CoFunction() {
	std::cout << __func__ << '\n';
	co_return ;
}

int main() {
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF) ;
	std::cout << "[main] Calling coroutine\n" ;
	auto task = CoFunction() ;
	std::cout << "[main] Resuming coroutine\n" ;
	//task.Resume() ;
	std::cout << "[main] End of main\n" ;
}