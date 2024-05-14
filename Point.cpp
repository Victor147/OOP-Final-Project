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

void Point::print() const {
	std::cout << " (" << x << ", " << y << ")";
}