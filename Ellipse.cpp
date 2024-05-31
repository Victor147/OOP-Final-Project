#include <iostream>
#include <cmath>
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

std::string Ellipse::getType() const {
	return "ellipse";
}

bool Ellipse::within(Figure* figure) const {
	return figure->contains(c) && figure->contains(Point(c.getX() + rx, c.getY())) &&
		figure->contains(Point(c.getX(), c.getY() + ry)) &&
		figure->contains(Point(c.getX() - rx, c.getY())) &&
		figure->contains(Point(c.getX(), c.getY() - ry));
}

double Ellipse::area() const {
	return 3.14159 * rx * ry;
}

double Ellipse::perimeter() const {
	return 2 * 3.14159 * sqrt((pow(rx-c.getX(), 2) + pow(ry-c.getY(), 2)) / 2);
}