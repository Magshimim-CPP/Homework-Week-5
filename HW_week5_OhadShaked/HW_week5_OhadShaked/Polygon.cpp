#include "Polygon.h"

Polygon::Polygon(const string& type, const string& name) : Shape(name, type)
{

}

void Polygon::move(const Point& other)
{
	for (int i = 0; i < _points.size(); i++)
	{
		_points[i] += other;
	}
}

Polygon::~Polygon()
{
}

double Polygon::getPerimeter() const
{
	double result = 0;

	result += _points[0].distance(_points[_points.size() - 1]);

	for (int i = 0; i < _points.size()-1; i++)
	{
		result += _points[i].distance(_points[i + 1]);
	}

	return result;
}

std::vector<Point> Polygon::getPoints() const
{
	return _points;
}