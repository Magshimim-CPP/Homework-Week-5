#include "Arrow.h"

/*
Constructor function for an arrow object.
Input: none
Output: none
*/
Arrow::Arrow(const Point& a, const Point& b, const string& type, const string& name) : _source(a), _destination(b), Shape(name, type)
{
	if (_source.getX() == _destination.getX() && _source.getY() == _destination.getY()) //checking that the 2 given points are not the same
	{
		//if they are the same, printing error and quiting the program.
		cout << RED;
		cout << SAME_POINT_ERROR << endl;
		cout << RESET_COLOR;
		Arrow::~Arrow();
		exit(1);
	}
}


/*
Destructor function for an arrow object.
Input: none
Output: none
*/
Arrow::~Arrow()
{
	_source.Point::~Point();
	_destination.Point::~Point();
}

/*
Function moves the arrow's source and destination points according to a given point.
Input: const Point& other
Output: none
*/
void Arrow::move(const Point& other)
{
	_source += other;
	_destination += other;
}

/*
Const 'get' function that returns the arrow's _source field (Point).
Input: none
Output: the shape's _source field (Point).
*/
Point Arrow::getSource() const
{
	return _source;
}

/*
Const 'get' function that returns the arrow's _destination field (Point).
Input: none
Output: the shape's _destination field (Point).
*/
Point Arrow::getDestination() const
{
	return _destination;
}

/*
Const 'get' function that returns the arrow's area (in this case, always 0).
Input: none
Output: double (0.0)
*/
double Arrow::getArea() const
{
	return 0.0;
}

/*
Const 'get' function that returns the arrow's perimeter.
Input: none
Output: double result.
*/
double Arrow::getPerimeter() const
{
	double result = _source.distance(_destination);
	return result;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}


