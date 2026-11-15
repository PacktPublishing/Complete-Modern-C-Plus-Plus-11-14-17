#include <iostream>
struct Point {
	int x;
	int y;
};
void DrawLine(int x1, int y1, int x2, int y2) {

}
//More natural and easy to understand
void DrawLine(Point start, Point end) {
	std::cout << start.x << std::endl; 
}
Point Create(int x,int y)
{
	//Validate the coordinate before constructing a point
	return {x, y};
}
int main() {
	//Point p1{10,10}; //aggregate initialization
	//Point p2{50,50} ;
	//DrawLine(p1, p2) ;

	DrawLine({10,10}, {50,50}) ;

	DrawLine(Create(10,10), Create(50,50)) ;
	return 0;
}