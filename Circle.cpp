#include "Circle.h"
#include <iostream>

Circle::Circle() : c(0, 0), r(0) {}
Circle::Circle(double _x, double _y, double _r, std::vector<Property>& _properties) : c(_x, _y), r(_r)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Circle::print(std::ostream& out, size_t ind) const {
	if (ind == -1)
	{
		out << "circle " << c.getX() << " " << c.getY() << " " << r << "\n";
	}
	else {
		out << ind << ". circle " << c.getX() << " " << c.getY() << " " << r;

		for (Property p : properties) {
			p.print(out);
		}

		out << std::endl;
	}
}

void Circle::translate(double horizontal, double vertical) {
	c.translate(horizontal, vertical);
}

void Circle::readFromFile(std::istream& in) {
	in >> c >> r;
}

void Circle::save(std::ostream& out) const {
	out << "<circle cx=\"" << c.getX() << "\" cy=\"" << c.getY() << "\" r=\"" << r << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />\n";
}

std::string Circle::getType() const {
	return "circle";
}

inline bool Circle::contains(const Point& p) const {
	return pow(p.getX() - c.getX(), 2) + pow(p.getY() - c.getY(), 2) <= pow(r, 2);
}

inline bool Circle::within(Figure* fig) const {
	return fig->contains(c) && fig->contains(Point(c.getX() + r, c.getY())) &&
		fig->contains(Point(c.getX(), c.getY() + r)) &&
		fig->contains(Point(c.getX() - r, c.getY())) &&
		fig->contains(Point(c.getX(), c.getY() - r));
}

//bool Circle::withinRectangle(Figure* rec) const {
//	Rectangle* rect = dynamic_cast<Rectangle*>(rec);
//	Point p1(c.getX() + r, c.getY());
//	Point p2(c.getX(), c.getY() + r);
//	Point p3(c.getX() - r, c.getY());
//	Point p4(c.getX(), c.getY() - r);
//
//	return rect->contains(c) && rect->contains(p1) && rect->contains(p2) && rect->contains(p3) && rect->contains(p4);
//}
//
//bool Circle::withinCircle(Figure* circ) const {
//	Circle* circle = dynamic_cast<Circle*>(circ);
//
//	return circle->contains(c) && circle->contains(Point(c.getX() + r, c.getY())) &&
//		circle->contains(Point(c.getX(), c.getY() + r)) &&
//		circle->contains(Point(c.getX() - r, c.getY())) &&
//		circle->contains(Point(c.getX(), c.getY() - r));
//}
//
Point& Circle::getCenter() {
	return c;
}

double Circle::getRadius() {
	return r;
}