#include "Polygon.h"

/*
Constructor function for a polygon object.
Input: const string& type, const string& name
Output: none
*/
Polygon::Polygon(const string& type, const string& name) : Shape(name, type)
{
}

/*
Function moves every point in the points vector to the given point.
Input: const Point& other
Output: none
*/
void Polygon::move(const Point& other)
{
	for (int i = ZERO; i < _points.size(); i++)
	{
		_points[i] += other;
	}
}

/*
Destructor function for a polygon object.
Input: none
Output: none
*/
Polygon::~Polygon()
{
}

/*
Const 'get' function that returns the polygon's perimeter value by calculating the distance between every two points (double result).
Input: none
Output: the polygon's perimeter value (double result).
*/
double Polygon::getPerimeter() const
{
	double result = ZERO;

	//calculating the polygon's perimeter value by adding the distance between every two points
	result += _points[ZERO].distance(_points[_points.size() - 1]);
	for (int i = ZERO; i < _points.size()-1; i++)
	{
		result += _points[i].distance(_points[i + 1]);
	}

	return result;
}

/*
Const 'get' function that returns the polygon's _points field (vector<Point>).
Input: none
Output: the polygon's _points field (vector<Point>).
*/
std::vector<Point> Polygon::getPoints() const
{
	return _points;
}