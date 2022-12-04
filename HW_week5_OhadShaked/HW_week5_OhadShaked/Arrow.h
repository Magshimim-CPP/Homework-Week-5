#pragma once
#include "Shape.h"

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
	Point getSource() const;
	Point getDestination() const;

	// Methods
	virtual void move(const Point& other) override;
	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)
};