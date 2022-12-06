#include "Triangle.h"

/*
Constructor function for a triangle object.
Input: const Point& a, const Point& b, const Point& c, const string& type, const string& name
Output: none
*/
Triangle::Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name) : Polygon(type, name)
{
	//if all points are on the same line, both on the x scale OR the y scalse, they cand create a triangle, printing error and quiting the program.
	if ((a.getX() == b.getX() && a.getX() == c.getX() && b.getX() == c.getX()) || (a.getY() == b.getY() && a.getY() == c.getY() && b.getY() == c.getY()))
	{
		cout << RED;
		cout << SAME_LINE_ERROR << endl;
		cout << RESET_COLOR;
		Triangle::~Triangle();
		exit(1);
	}
	//pushing the points by order to the points vector.
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}

/*
Destructor function for a triangle object.
Input: none
Output: none
*/
Triangle::~Triangle()
{

}

/*
Const get function to calculate and return the area of a triangle object (Formula: Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By)) (double result)
Input: none
Output: the area of a triangle object (double result)
*/
double Triangle::getArea() const
{
	double result = abs(_points[0].getX() * (_points[1].getY() - _points[2].getY()) + _points[1].getX() * (_points[2].getY() - _points[0].getY()) + _points[2].getX() * (_points[0].getY() - _points[1].getY()))/2;
	return result;
}

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
