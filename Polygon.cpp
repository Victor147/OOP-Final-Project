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

void Polygon::print(size_t ind) const {
	std::cout << ind << ". polygon -";

	for (size_t i = 0; i < points.size(); ++i) {
		points[i].print();
		if (i != points.size() - 1)
		{
			std::cout << ", ";
		}
	}

	for (Property p : properties) {
		p.print();
	}

	std::cout << std::endl;
}

void Polygon::translate(double horizontal, double vertical) {
	for (Point& p : points) {
		p.translate(horizontal, vertical);
	}
}

void Polygon::readFromFile(std::istream& in) {

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