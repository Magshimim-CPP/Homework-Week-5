#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:

		// Constructor
		// There's a need only for the top left corner 
		Rectangle(const Point& a, double length, double width, const string& type, const string& name);

		// Destructor
		virtual ~Rectangle();

		// Methods
		virtual double getArea() const override;
		virtual void draw(const Canvas& canvas) override;
		virtual void clearDraw(const Canvas& canvas) override;

		// override functions if need (virtual + pure virtual)

		// Add Fields if necessary
	};
}