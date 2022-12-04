#include "Rectangle.h"


myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const string& type, const string& name) : Polygon(type, name)
{
	_length = length;
	_width = width;
	_points.push_back(a);
	_points.push_back(Point(a.getX() + length, a.getY()));
	_points.push_back(Point(a.getX() + length, a.getY() + width));
	_points.push_back(Point(a.getX(), a.getY() + width));
}

myShapes::Rectangle::~Rectangle()
{

}

double myShapes::Rectangle::getArea() const
{
	return (_length * _width);
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}


