#include "Point.h"
#include <cmath>

/*
Constructor function for a point object (sets to 0).
Input: none
Output: none
*/
Point::Point()
{
	_x = ZERO;
	_y = ZERO;
}

/*
Constructor function for a point object (with values).
Input: none
Output: none
*/
Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}

/*
Destructor function for a point object.
Input: none
Output: none
*/
Point::~Point()
{
	_x = ZERO;
	_y = ZERO;
}

/*
Function for operator overloading on '+' to create and return a new point with 'this' point's x and y values added with the given point's x and y values.
Input: const Point& other
Output: Point result
*/
Point Point::operator+(const Point& other) const
{
	Point result = Point(_x + other._x, _y + other._y);
	return result;
}

/*
Function for operator overloading on '+=' to add the x and y values of a given point to 'this' point.
Input: const Point& other
Output: *this
*/
Point& Point::operator+=(const Point& other)
{
	_x += other._x;
	_y += other._y;
	return *this;
}

/*
Const 'get' function that returns the point's _x field (double).
Input: none
Output: the point's _x field (double).
*/
double Point::getX() const
{
	return _x;
}

/*
Const 'get' function that returns the point's _y field (double).
Input: none
Output: the point's _y field (double).
*/
double Point::getY() const
{
	return _y;
}

/*
Function to calculate and return the distance between 2 point objects.
Input: const Point& other
Output: the distance between 2 point objects (double result)
*/
double Point::distance(const Point& other) const
{
	double X1 = this->getX();
	double Y1 = this->getY();
	double X2 = other.getX();
	double Y2 = other.getY();

	double result = sqrt(pow(X1 - X2, 2.0) + pow(Y1 - Y2, 2.0)); //math equation for distance.

	return result;
}
