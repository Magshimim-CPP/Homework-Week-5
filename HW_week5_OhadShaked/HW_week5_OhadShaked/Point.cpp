#include "Point.h"
#include <cmath>

Point::Point()
{
	_x = ZERO;
	_y = ZERO;
}

Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}

Point::~Point()
{
	_x = ZERO;
	_y = ZERO;
}

Point Point::operator+(const Point& other) const
{
	Point result = Point(_x + other._x, _y + other._y);
	return result;
}

Point& Point::operator+=(const Point& other)
{
	_x += other._x;
	_y += other._y;
	return *this;
}

double Point::getX() const
{
	return _x;
}

double Point::getY() const
{
	return _y;
}

double Point::distance(const Point& other) const
{
	double X1 = this->getX();
	double Y1 = this->getY();
	double X2 = other.getX();
	double Y2 = other.getY();

	double result = sqrt(pow(X1 - X2, 2.0) + pow(Y1 - Y2, 2.0)); //math equation for distance.

	return result;
}
