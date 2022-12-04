#pragma once
#include "Shape.h"

#define SAME_POINT_ERROR "ERROR: 2 of the same points recived."

class Arrow : public Shape
{
private:
	Point _source;
	Point _destination;

public:

	// Constructor
	Arrow(const Point& a, const Point& b, const string& type, const string& name);

	// Destructor
	~Arrow();

	// Getters
	virtual double getArea() const;
	virtual double getPerimeter() const;
	Point getSource() const;
	Point getDestination() const;

	// Methods
	virtual void move(const Point& other) override;
	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)
};