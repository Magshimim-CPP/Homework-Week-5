#include "Shape.h"

/*
Constructor function for an shape object.
Input: none
Output: none
*/
Shape::Shape(const string& name, const string& type)
{
	_name = name;
	_type = type;
}

/*
Function to print the shape's details.
Input: none
Output: none
*/
void Shape::printDetails() const
{
	cout << "\nSHAPE INFO\nType: " << this->getType() << "\nName: " << this->getName() << "\nArea: " << this->getArea() << "\nPerimeter: " << this->getPerimeter() << "\n" << endl;
}

/*
Const 'get' function that returns the shape's _type field (string).
Input: none
Output: the shape's _type field (string).
*/
string Shape::getType() const
{
	return _type;
}

/*
Const 'get' function that returns the shape's _name field (string).
Input: none
Output: the shape's _name field (string).
*/
string Shape::getName() const
{
	return _name;
}

/*
Destructor function for an shape object.
Input: none
Output: none
*/
Shape::~Shape()
{
	//cleaning the type and name fields.
	_name = "";
	_type = "";
}