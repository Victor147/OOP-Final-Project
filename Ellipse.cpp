#include <iostream>
#include "Ellipse.h"

Ellipse::Ellipse() : c(0, 0), rx(0), ry(0) {}
Ellipse::Ellipse(double _cx, double _cy, double _rx, double _ry, std::vector<Property>& _properties) : c(_cx, _cy), rx(_rx), ry(_ry) {
	for (Property p : _properties) {
		properties.push_back(p);
	}
}

void Ellipse::print(std::ostream& out, size_t ind) const {
	out << ind << ". ellipse " << c.getX() << " " << c.getY() << " " << rx << " " << ry;

	for (Property p : properties) {
		p.print(out);
	}

	out << std::endl;
}

void Ellipse::translate(double horizontal, double vertical) {
	c.translate(horizontal, vertical);
}

void Ellipse::save(std::ostream& out) const {
	out << "<ellipse cx=\"" << c.getX() << "\" cy=\"" << c.getY() << "\" rx=\"" << rx << "\" ry=\"" << ry << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />\n";
}

bool Ellipse::contains(const Point& point) const {
	return false;
}

void Ellipse::readFromFile(std::istream& in) {
	in >> c;
	in >> rx;
	in >> ry;
}

bool Ellipse::within(Figure* figure) const {
	return figure->contains(c) && figure->contains(Point(c.getX() + rx, c.getY())) &&
		figure->contains(Point(c.getX(), c.getY() + ry)) &&
		figure->contains(Point(c.getX() - rx, c.getY())) &&
		figure->contains(Point(c.getX(), c.getY() - ry));
}

//bool Ellipse::withinRectangle(Figure* rectangle) const {
//	Rectangle* rect = dynamic_cast<Rectangle*>(rectangle);
//	return rect->contains(c) && rx <= rect->getWidth() - c.getX() && ry <= rect->getHeight() - c.getY();
//}
//
//bool Ellipse::withinCircle(Figure* circ) const {
//	Circle* circle = dynamic_cast<Circle*>(circ);
//	return circle->contains(c) && circle->contains(Point(c.getX() + rx, c.getY())) &&
//		circle->contains(Point(c.getX(), c.getY() + ry)) &&
//		circle->contains(Point(c.getX() - rx, c.getY())) &&
//		circle->contains(Point(c.getX(), c.getY() - ry));
//}