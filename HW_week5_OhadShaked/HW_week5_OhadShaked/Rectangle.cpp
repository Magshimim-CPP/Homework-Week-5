#include "Rectangle.h"


/*
Constructor function for a rectangle object.
Input: const Point& a, double length, double width, const string& type, const string& name
Output: none
*/
myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const string& type, const string& name) : Polygon(type, name)
{
	_length = length;
	_width = width;
	//pushing all 4 points of the rectangle to the points vector by order.
	_points.push_back(a);
	_points.push_back(Point(a.getX() + length, a.getY()));
	_points.push_back(Point(a.getX() + length, a.getY() + width));
	_points.push_back(Point(a.getX(), a.getY() + width));
}

/*
Destructor function for a rectangle object.
Input: none
Output: none
*/
myShapes::Rectangle::~Rectangle()
{

}

/*
Const get function to calculate and return the area of a rectangle object (Formula: length * width) (double)
Input: none
Output: the area of a rectangle object (double)
*/
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


