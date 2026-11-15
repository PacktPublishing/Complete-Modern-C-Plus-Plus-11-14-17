#include <stack>
#include <print>
#include <iostream>
#include <queue>
#include <random>
int main() {
	std::stack<int> s ;
	for (int i = 0 ; i < 5 ; ++i) {
		s.push(i) ;
	}
	std::println("Stack");
	while (!s.empty()) {
		std::cout << s.top() <<' ' ;
		s.pop();
	}
	std::println("\nQueue");

	std::queue<int> q;
	for (int i = 0 ; i < 5 ; ++i) {
		q.push(i);
	}
	while (!q.empty()){
		std::cout << q.front() << ' ';
		q.pop();
	}

	std::println("\nPriority Queue");
	std::mt19937 engine{std::random_device{}()};
	std::uniform_int_distribution<int> dist{0,10};
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0 ; i < 5 ; ++i) {
		auto num = dist(engine);
		std::cout << num << ' ' ;
		pq.push(num);
	}
	std::println();
	while (!pq.empty()){
		std::cout << pq.top() << ' ';
		pq.pop();
	}
}