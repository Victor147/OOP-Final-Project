#include <iostream>
#include "Circle.h"

Circle::Circle() : x(0), y(0), r(0) {}
Circle::Circle(double _x, double _y, double _r, std::vector<Property>& _properties) : x(_x), y(_y), r(_r)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Circle::print() const {
	std::cout << "circle " << x << " " << y << " " << r;

	for (Property p : properties) {
		p.print();
	}	

	std::cout << std::endl;
}

void Circle::translate(size_t ind) {

}

void Circle::within() const {

}

void Circle::loadFigure() {

}