#include <iostream>
#include "Ellipse.h"

Ellipse::Ellipse() : c(0, 0), rx(0), ry(0) {}
Ellipse::Ellipse(double _cx, double _cy, double _rx, double _ry, std::vector<Property>& _properties) : c(_cx, _cy), rx(_rx), ry(_ry) {
	for (Property p : _properties) {
		properties.push_back(p);
	}
}

void Ellipse::print(size_t ind) const {
	std::cout << ind << ". ellipse " << c.getX() << " " << c.getY() << " " << rx << " " << ry;

	for (Property p : properties) {
		p.print();
	}

	std::cout << std::endl;
}

void Ellipse::translate(double horizontal, double vertical) {
	c.translate(horizontal, vertical);
}

void Ellipse::within() const {

}