#pragma once
#include "Point.h"
#include "Canvas.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Shape 
{
public:

	// Constructor
	Shape(const string& name, const string& type);

	// Destructor
	virtual ~Shape();

	// Getters
	string getType() const;
	string getName() const;

	// Methods
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void move(const Point& other) = 0; // add the Point to all the points of shape
	void printDetails() const;

	virtual void draw(const Canvas& canvas) = 0;
	virtual void clearDraw(const Canvas& canvas) = 0;

private:
	string _name;
	string _type;
};