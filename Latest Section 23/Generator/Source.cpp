#include <coroutine>
#include <iostream>
//#define LOGGING_ON
#ifdef LOGGING_ON
#define LOG std::cout << __func__ << '\n'
#else
#define LOG ((void)0)
#endif

class Generator {
public:
	struct promise_type {
		promise_type() {
			LOG;
		}
		~promise_type() {
			LOG;
		}
		Generator get_return_object() {
			LOG;
			auto handle = std::coroutine_handle<promise_type>::from_promise(*this) ;
			return {handle};
		}
		std::suspend_never initial_suspend() {
			LOG;
			return {};
		}
		std::suspend_always final_suspend()noexcept {
			LOG;
			return {};
		}
		void unhandled_exception() {
			
		}
		std::suspend_always yield_value(int value) {
			LOG;
			m_Value = value ;
			return {};
		}
		void return_void() {
			LOG;
		}
		int m_Value{};
	};
	int GetValue()const {
		return m_Handle.promise().m_Value;
	}
	bool Done()const {
		return !m_Handle || m_Handle.done();
	}
	void Resume() {
		if (m_Handle && !m_Handle.done()) {
			m_Handle.resume() ;
		}
	}
	Generator(const std::coroutine_handle<promise_type> &handle):m_Handle{handle} {
		LOG;
	}
	~Generator() {
		LOG;
		if (m_Handle) {
			m_Handle.destroy();
		}
	}
private:
	std::coroutine_handle<promise_type> m_Handle{} ;

};

Generator Generate() {
	for (int i = 0 ; i < 5 ; ++i) {
		co_yield i;
	}
	co_return ;
}

int main() {
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF) ;
	std::cout << "[main] Calling coroutine\n" ;
	auto task = Generate() ;
	std::cout << "[main] Resuming coroutine\n" ;
	while (!task.Done()) {
		std::cout << task.GetValue() << ' ';
		task.Resume();
	}
	//task.Resume() ;
	std::cout << "[main] End of main\n" ;
}