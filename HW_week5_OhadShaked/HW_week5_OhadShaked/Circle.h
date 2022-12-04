#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
protected:
	Point _center;
	double _radius;

public:

	// Constructor
	Circle(const Point& center, double radius, const string& type, const string& name);

	// Destructor
	~Circle();

	// Getters
	virtual Point getCenter() const;
	virtual double getRadius() const;
	virtual double getArea() const;
	virtual double getPerimeter() const;


	// Methods
	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;
	virtual void move(const Point& other);

	// add fields
	// override functions if need (virtual + pure virtual)

};