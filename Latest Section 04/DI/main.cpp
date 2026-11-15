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
	return {.x=x, .y=y};
}
void UsingPoint()
{
	Point p1{.x=10,.y=10}; //aggregate initialization
	Point p2{.x=50,.y=50} ;
	DrawLine(p1, p2) ;

	DrawLine({.x=10,.y=10}, {.x{50},.y{50}}) ;

	DrawLine(Create(10,10), Create(50,50)) ;
}

struct EmployeeDetails
{
	int id;
	int age;
	int deptId;
	int salary;
};
void ProcessEmployee(EmployeeDetails empDetails)
{
	
}
int main() {
	ProcessEmployee({.id=58,.age=45,.deptId=70,.salary=65});
	return 0;
}