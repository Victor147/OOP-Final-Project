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

void Line::print(std::ostream& out, size_t ind) const {
	out << ind << ". line " << p1.getX() << " " << p1.getY() << " " << p2.getX() << " " << p2.getY();

	for (Property p : properties) {
		p.print(out);
	}

	out << std::endl;
}

void Line::translate(double horizontal, double vertical) {
	p1.translate(horizontal, vertical);
	p2.translate(horizontal, vertical);
}

void Line::readFromFile(std::istream& in) {
	in >> p1 >> p2;
}

void Line::save(std::ostream& out) const {
	out << "<line x1=\"" << p1.getX() << "\" y1=\"" << p1.getY() << "\" x2=\"" << p2.getX() << "\" y2=\"" << p2.getY() << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />" << std::endl;
}

std::string Line::getType() const {
	return "line";
}

bool Line::contains(const Point& p) const {
	return false;
}

bool Line::within(Figure* fig) const {
	return fig->contains(p1) && fig->contains(p2);
}

//bool Line::withinRectangle(Figure* rect) const {
//	Rectangle* rectangle = dynamic_cast<Rectangle*>(rect);
//	return rectangle->contains(p1) && rectangle->contains(p2);
//}
//
//bool Line::withinCircle(Figure* c) const {
//	Circle* circle = dynamic_cast<Circle*>(c);
//	return circle->contains(p1) && circle->contains(p2);
//}