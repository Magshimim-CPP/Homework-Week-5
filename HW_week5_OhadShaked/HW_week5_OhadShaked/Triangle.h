#include "Polygon.h"
#include <string>

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

	// override functions if need (virtual + pure virtual)

};