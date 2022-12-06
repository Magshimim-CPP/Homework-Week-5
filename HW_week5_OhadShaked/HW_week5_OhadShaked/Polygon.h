#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(const string& type, const string& name);

	// Destructor
	virtual ~Polygon();

	// Methods
	virtual void move(const Point& other) override;

	// Getters
	virtual double getPerimeter() const override;
	std::vector<Point> getPoints() const;

protected:
	std::vector<Point> _points;
};