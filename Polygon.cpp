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

void Polygon::translate(size_t ind) {

}

void Polygon::within() const {

}

void Polygon::loadFigure() {

}