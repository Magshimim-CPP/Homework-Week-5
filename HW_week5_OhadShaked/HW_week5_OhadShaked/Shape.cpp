#include "Shape.h"

Shape::Shape(const string& name, const string& type)
{
	_name = name;
	_type = type;
}

void Shape::printDetails() const
{
	std::cout << "Name : " << _name << std::endl;
	std::cout << "Type : " << _type << std::endl;

}

string Shape::getType() const
{
	return _type;
}

string Shape::getName() const
{
	return _name;
}

Shape::~Shape()
{
	_name = "";
	_type = "";
}