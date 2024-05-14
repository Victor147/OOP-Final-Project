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

void Polyline::print(size_t ind) const {
	std::cout << ind << ". polyline -";

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

void Polyline::translate(size_t ind) {

}

void Polyline::within() const {

}

void Polyline::loadFigure() {

}
