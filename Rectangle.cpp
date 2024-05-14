#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : p(0, 0), width(0), height(0) {}
Rectangle::Rectangle(double _x, double _y, double _width, double _height) : p(_x, _y), width(_width), height(_height) {}

Rectangle::Rectangle(double _x, double _y, double _width, double _height, std::vector<Property>& _properties) : Rectangle(_x, _y, _width, _height)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Rectangle::print(size_t ind) const {
	std::cout << ind << ". rectangle " << p.getX() << " " << p.getY() << " " << width << " " << height;

	for (Property p : properties) {
		p.print();
	}

	std::cout << std::endl;
}

void Rectangle::translate(size_t ind) {

}

void Rectangle::within() const {

}

void Rectangle::loadFigure() {

}