#include "Circle.h"

/*
Constructor function for a circle object.
Input: const Point& center, double radius, const string& type, const string& name
Output: none
*/
Circle::Circle(const Point& center, double radius, const string& type, const string& name) : Shape(name, type)
{
	//checking if the radius is negative
	if (radius < 0)
	{
		//if it is, printing red error message and quiting the program.
		cout << RED;
		cout << NEGATIVE_RADIUS_ERROR << endl;
		cout << RESET_COLOR;
		Circle::~Circle();
		exit(1);
	}
	_center = center;
	_radius = radius;
}

/*
Destructor function for a circle object.
Input: none
Output: none
*/
Circle::~Circle()
{

}

/*
Const 'get' function that returns the circle's _center field (Point).
Input: none
Output: the circle's _center field (Point).
*/
Point Circle::getCenter() const
{
	return _center;
}

/*
Const 'get' function that returns the circle's _radius field (double).
Input: none
Output: the circle's _radius field (double).
*/
double Circle::getRadius() const
{
	return _radius;
}

/*
Function moves the circle's center to a given point.
Input: const Point& other
Output: none
*/
void  Circle::move(const Point& other)
{
	_center += other;
}

/*
Const 'get' function that returns the circle's area value (double).
Input: none
Output: the circle's area value (double).
*/
double Circle::getArea() const
{
	double result = PI * pow(_radius, 2);
	return result;
}

/*
Const 'get' function that returns the circle's perimeter value (double).
Input: none
Output: the circle's perimeter value (double).
*/
double Circle::getPerimeter() const
{
	double result = 2 * (PI * _radius);
	return result;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


