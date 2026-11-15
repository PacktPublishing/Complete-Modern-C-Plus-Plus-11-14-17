#include <iostream>
#include <cmath>
class Point {
public:
	constexpr Point(int x, int y)
		: m_x{ x }, m_y{ y } {}

	constexpr int GetX() const {
		return m_x;
	}
	constexpr int GetY() const {
		return m_y;
	}
	void SetX(int x) {
		m_x = x ;
	}
	void SetY(int y) {
		m_y = y;
	}
private:
	int m_x;
	int m_y;
};

constexpr Point CreatePointFrom(int x, int y) {
	//validate x & y here
	return { x,y };
}

double Distance(const Point& start, const Point& end) {
	return std::hypot(end.GetX() - start.GetX(), end.GetY() - start.GetY());
}

int main() {
	constexpr Point origin{ 0,0 };
	constexpr auto end = CreatePointFrom(640, 480);

	constexpr Point labels[]{ {10,10}, {20, 20}, {30, 30} };

	auto x = origin.GetX() ;
	constexpr auto y = origin.GetY() ;

	auto distance = Distance(labels[0], labels[1]) ;

}