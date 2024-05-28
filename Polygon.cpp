#include <iostream>
#include "Polygon.h"

Polygon::Polygon(std::vector<Point>& _points, std::vector<Property>& _properties) {
	for (Point p : _points) {
		points.push_back(p);
	}
	for (Property p : _properties) {
		properties.push_back(p);
	}
}

void Polygon::print(std::ostream& out, size_t ind) const {
	out << ind << ". polygon -";

	for (size_t i = 0; i < points.size(); ++i) {
		points[i].print(out);
		if (i != points.size() - 1)
		{
			out << ", ";
		}
	}

	for (Property p : properties) {
		p.print(out);
	}

	out << std::endl;
}

void Polygon::translate(double horizontal, double vertical) {
	for (Point& p : points) {
		p.translate(horizontal, vertical);
	}
}

void Polygon::readFromFile(std::istream& in) {

}

void Polygon::save(std::ostream& out) const {
	out << "<polygon points=\"";
	for (size_t i = 0; i < points.size(); ++i) {
		points[i].save(out);
		if (i != points.size() - 1)
		{
			out << " ";
		}
	}
	out << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />\n";
}

std::string Polygon::getType() const {
	return "polygon";
}

bool Polygon::contains(const Point& p) const {
	return false;
}

bool Polygon::within(Figure* fig) const {
	for (Point p : points) {
		if (!fig->contains(p)) {
			return false;
		}
	}
	return true;
}

//bool Polygon::withinRectangle(Figure* rectangle) const {
//	Rectangle* rect = dynamic_cast<Rectangle*>(rectangle);
//	for (Point p : points) {
//		if (!rect->contains(p)) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool Polygon::withinCircle(Figure* c) const {
//	Circle* circle = dynamic_cast<Circle*>(c);
//	for (Point p : points) {
//		if (!circle->contains(p)) {
//			return false;
//		}
//	}
//	return true;
//}