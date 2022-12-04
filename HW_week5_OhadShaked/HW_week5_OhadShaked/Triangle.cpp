#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name) : Polygon(type, name)
{
	if ((a.getX() == b.getX() && a.getX() == c.getX() && b.getX() == c.getX()) || (a.getY() == b.getY() && a.getY() == c.getY() && b.getY() == c.getY()))
	{
		cout << SAME_LINE_ERROR << endl;
		Triangle::~Triangle();
		exit(1);
	}
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}

Triangle::~Triangle()
{

}

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
