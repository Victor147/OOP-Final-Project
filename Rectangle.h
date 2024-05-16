#pragma once
#include "Point.h"
#include "Figure.h"

class Rectangle : public Figure
{
private:
	Point p;
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);
	Rectangle(double _x, double _y, double _width, double _height, std::vector<Property>& _properties);

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);
	void within() const;
};