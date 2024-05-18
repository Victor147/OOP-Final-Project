#include <iostream>
#include "Circle.h"
#include "Property.h"
#include "Rectangle.h"

Circle::Circle() : c(0, 0), r(0) {}
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

void Circle::translate(double horizontal, double vertical) {
	c.translate(horizontal, vertical);
}

bool Circle::withinRectangle(Figure* r) const {
	Rectangle* rect = dynamic_cast<Rectangle*>(r);
	return false;
	//TODO
}

bool Circle::withinCircle(Figure* c) const {
	Circle* circle = dynamic_cast<Circle*>(c);
	return false;
	//TODO
}

Point& Circle::getCenter() {
	return c;
}

double Circle::getRadius() {
	return r;
}

bool Circle::contains(const Point& point) const {
	return pow(point.getX() - c.getX(), 2) + pow(point.getY() - c.getY(), 2) <= pow(r, 2);
}