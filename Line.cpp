#include <iostream>
#include "Line.h"


Line::Line() : p1(0, 0), p2(0, 0) {}
Line::Line(double _x1, double _y1, double _x2, double _y2, std::vector<Property>& _properties) : p1(_x1, _y1), p2(_x2, _y2)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Line::print(size_t ind) const {
	std::cout << ind << ". line " << p1.getX() << " " << p1.getY() << " " << p2.getX() << " " << p2.getY();

	for (Property p : properties) {
		p.print();
	}

	std::cout << std::endl;
}

void Line::translate(size_t ind) {

}

void Line::within() const {

}

void Line::loadFigure() {

}