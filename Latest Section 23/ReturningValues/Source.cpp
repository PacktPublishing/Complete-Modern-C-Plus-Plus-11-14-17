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
		std::suspend_always final_suspend()noexcept {
			std::cout << __func__ << '\n';
			return {};
		}
		void unhandled_exception() {
			
		}
		void return_value(int value) {
			std::cout << __func__ << '\n';
			m_Value = value ;
		}
		int m_Value{};
	};
	int GetValue()const {
		return m_Handle.promise().m_Value;
	}
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
			m_Handle.destroy();
		}
	}
private:
	std::coroutine_handle<promise_type> m_Handle{} ;

};

Task CoAdd(int x,int y) {
	std::cout << __func__ << '\n';
	co_return x+y;
}

int main() {
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF) ;
	std::cout << "[main] Calling coroutine\n" ;
	auto task = CoAdd(5,7) ;
	std::cout << "[main] Resuming coroutine\n" ;
	//task.Resume() ;
	std::cout << "Result:" << task.GetValue() << '\n';
	std::cout << "[main] End of main\n" ;
}