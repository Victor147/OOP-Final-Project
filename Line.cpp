#include <iostream>
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"


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

void Line::translate(double horizontal, double vertical) {
	p1.translate(horizontal, vertical);
	p2.translate(horizontal, vertical);
}

bool Line::withinRectangle(Figure* rect) const {
	Rectangle* rectangle = dynamic_cast<Rectangle*>(rect);
	return rectangle->contains(p1) && rectangle->contains(p2);
}

bool Line::withinCircle(Figure* c) const {
	Circle* circle = dynamic_cast<Circle*>(c);
	return circle->contains(p1) && circle->contains(p2);
}