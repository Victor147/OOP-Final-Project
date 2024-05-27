#include <iostream>
#include "Point.h"

Point::Point() :x(0), y(0) {}
Point::Point(double _x, double _y) : x(_x), y(_y) {}

double Point::getX() const {
	return x;
}
double Point::getY() const {
	return y;
}

void Point::setX(double _x) {
	x = _x;
}

void Point::setY(double _y) {
	y = _y;
}

void Point::translate(double horizontal, double vertical) {
	x += horizontal;
	y += vertical;
}

void Point::print(std::ostream& out) const {
	out << " (" << x << ", " << y << ")";
}

void Point::save(std::ostream& out) const {
	out << x << "," << y;
}	