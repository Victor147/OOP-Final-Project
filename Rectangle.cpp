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
	out << ind << ". rectangle " << p.getX() << " " << p.getY() << " " << width << " " << height;

	for (Property p : properties) {
		p.print(out);
	}

	out << std::endl;
}

void Rectangle::translate(double horizontal, double vertical) {
	p.translate(horizontal, vertical);
}

void Rectangle::readFromFile(std::istream& in) {
	in >> p >> width >> height;
}

void Rectangle::save(std::ostream& out) const {
	out << "<rect x=\"" << p.getX() << "\" y=\"" << p.getY() << "\" width=\"" << width << "\" height=\"" << height << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />" << std::endl;
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

//bool Rectangle::withinRectangle(Figure* r) const {
//	Rectangle* rect = dynamic_cast<Rectangle*>(r);
//	/*return rect.contains(p) && rect.contains(Point(p.getX() + width, p.getY())) &&
//		rect.contains(Point(p.getX(), p.getY() + height)) &&
//		rect.contains(Point(p.getX() + width, p.getY() + height));*/
//	return rect->contains(p) && width <= rect->getWidth() - p.getX() && height <= rect->getHeight() - p.getY();
//}
//
//bool Rectangle::withinCircle(Figure* c) const {
//	Circle* circle = dynamic_cast<Circle*>(c);
//	return circle->contains(p) && circle->contains(Point(p.getX() + width, p.getY())) &&
//		circle->contains(Point(p.getX(), p.getY() + height)) &&
//		circle->contains(Point(p.getX() + width, p.getY() + height));
//}

Point& Rectangle::getPoint() {
	return p;
}

double Rectangle::getWidth() {
	return width;
}

double Rectangle::getHeight() {
	return height;
}