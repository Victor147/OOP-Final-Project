#include <iostream>
#include "Circle.h"

Circle::Circle() : c(0,0), r(0) {}
Circle::Circle(double _x, double _y, double _r, std::vector<Property>& _properties) : c(_x, _y), r(_r)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Circle::print(size_t ind) const {
	std::cout << ind << ". circle " << c.getX() << " " << c.getY() << " " << r;

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