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
	if (ind == -1)
	{
		out << "line " << p1.getX() << " " << p1.getY() << " " << p2.getX() << " " << p2.getY() << "\n";
	}
	else {
		out << ind << ". line " << p1.getX() << " " << p1.getY() << " " << p2.getX() << " " << p2.getY();

		for (Property p : properties) {
			p.print(out);
		}

		out << std::endl;
	}
}

void Line::translate(double horizontal, double vertical) {
	p1.translate(horizontal, vertical);
	p2.translate(horizontal, vertical);
}

void Line::readFromFile(std::istream& in) {
	in >> p1 >> p2;
	std::string fill, stroke;
	if (in >> fill)
	{
		Property p("fill", fill);
		properties.push_back(p);
	}
	if (in >> stroke)
	{
		Property p("stroke", stroke);
		properties.push_back(p);
	}
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

Figure* Line::clone() const {
	return new Line(*this);
}

bool Line::contains(const Point& p) const {
	return false;
}

bool Line::within(Figure* fig) const {
	return fig->contains(p1) && fig->contains(p2);
}

double Line::length() const {
	return p1.distance(p2);
}