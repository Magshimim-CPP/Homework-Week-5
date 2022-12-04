#include "Arrow.h"

Arrow::Arrow(const Point& a, const Point& b, const string& type, const string& name) : _source(a), _destination(b), Shape(name, type)
{
	if (_source.getX() == _destination.getX() && _source.getY() == _destination.getY())
	{
		cout << SAME_POINT_ERROR << endl;
		Arrow::~Arrow();
		exit(1);
	}
}

Arrow::~Arrow()
{
	_source.Point::~Point();
	_destination.Point::~Point();
}

void Arrow::move(const Point& other)
{
	_source += other;
	_destination += other;
}

Point Arrow::getSource() const
{
	return _source;
}

Point Arrow::getDestination() const
{
	return _destination;
}

double Arrow::getArea() const
{
	return 0.0;
}

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


