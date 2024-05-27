#include <iostream>
#include "Polyline.h"

Polyline::Polyline(std::vector<Point>& _points, std::vector<Property>& _properties) {
	for (Point p : _points) {
		points.push_back(p);
	}
	for (Property p : _properties)
	{
		properties.push_back(p);
	}
}

void Polyline::print(std::ostream& out, size_t ind) const {
	out << ind << ". polyline -";

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

void Polyline::translate(double horizontal, double vertical) {
	for (Point& p : points) {
		p.translate(horizontal, vertical);
	}
}

void Polyline::readFromFile(std::istream& in) {

}

void Polyline::save(std::ostream& out) const {
	out << "<polyline points=\"";
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

bool Polyline::contains(const Point& point) const {
	return false;
}

bool Polyline::within(Figure* fig) const {
	for (Point p : points) {
		if (!fig->contains(p))
		{
			return false;
		}
	}
	return true;
}

//bool Polyline::withinRectangle(Figure* rectangle) const {
//	Rectangle* rect = dynamic_cast<Rectangle*>(rectangle);
//	for (Point p : points) {
//		if (!rect->contains(p)) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool Polyline::withinCircle(Figure* c) const {
//	Circle* circle = dynamic_cast<Circle*>(c);
//	for (Point p : points) {
//		if (!circle->contains(p)) {
//			return false;
//		}
//	}
//	return true;
//}