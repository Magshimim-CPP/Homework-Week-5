#include "Polygon.h"
#include <string>

#define SAME_LINE_ERROR "ERROR: all of the recived points are located on the same line, and dose not create a triangle." //defined string for error message

class Triangle : public Polygon
{
public:
	
	// Constructor
	Triangle(const Point& a, const Point& b, const Point& c, const string& type, const string& name);

	// Destructor
	virtual ~Triangle();

	// Methods
	virtual double getArea() const override;
	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;

};