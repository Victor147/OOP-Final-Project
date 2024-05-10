#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), width(0), length(0) {}
Rectangle::Rectangle(double _x, double _y, double _width, double _length) : x(_x), y(_y), width(_width), length(_length) {}

void Rectangle::print() const {
	std::cout << "rectangle " << x << " " << y << " " << width << " " << length;

	for (Property* p : properties) {
		p->print();
	}

	std::cout << std::endl;
}