#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : p(0, 0), width(0), height(0) {}
Rectangle::Rectangle(double _x, double _y, double _width, double _height) : p(_x, _y), width(_width), height(_height) {}

Rectangle::Rectangle(double _x, double _y, double _width, double _height, std::vector<Property>& _properties) : Rectangle(_x, _y, _width, _height)
{
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Rectangle::print(std::ostream& out, size_t ind) const {
	if (ind == -1)
	{
		out << "rectangle " << p.getX() << " " << p.getY() << " " << width << " " << height << "\n";
	}
	else {
		out << ind << ". rectangle " << p.getX() << " " << p.getY() << " " << width << " " << height;

		for (Property p : properties) {
			p.print(out);
		}

		out << std::endl;
	}
}

void Rectangle::translate(double horizontal, double vertical) {
	p.translate(horizontal, vertical);
}

void Rectangle::readFromFile(std::istream& in) {
	in >> p >> width >> height;
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

void Rectangle::save(std::ostream& out) const {
	out << "<rect x=\"" << p.getX() << "\" y=\"" << p.getY() << "\" width=\"" << width << "\" height=\"" << height << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />" << std::endl;
}

Figure* Rectangle::clone() const {
	return new Rectangle(*this);
}

std::string Rectangle::getType() const {
	return "rectangle";
}

bool Rectangle::contains(const Point& point) const {
	return point.getX() >= p.getX() && point.getX() <= p.getX() + width &&
		point.getY() >= p.getY() && point.getY() <= p.getY() + height;
}

bool Rectangle::within(Figure* fig) const {
	return fig->contains(p) && fig->contains(Point(p.getX() + width, p.getY()))&&
				fig->contains(Point(p.getX(), p.getY() + height)) &&
				fig->contains(Point(p.getX() + width, p.getY() + height));
}

double Rectangle::area() const {
	return width * height;
}

double Rectangle::perimeter() const {
	return 2 * (width + height);
}

Point& Rectangle::getPoint() {
	return p;
}

double Rectangle::getWidth() {
	return width;
}

double Rectangle::getHeight() {
	return height;
}