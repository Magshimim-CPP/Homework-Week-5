#include "Circle.h"

Circle::Circle(const Point& center, double radius, const string& type, const string& name) : Shape(name, type)
{
	if (radius < 0)
	{
		cout << NEGATIVE_RADIUS_ERROR << endl;
		Circle::~Circle();
		exit(1);
	}
	_center = center;
	_radius = radius;
}

Circle::~Circle()
{

}

Point Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const
{
	return _radius;
}

void  Circle::move(const Point& other)
{
	_center += other;
}

double Circle::getArea() const
{
	double result = PI * pow(_radius, 2);
	return result;
}

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


