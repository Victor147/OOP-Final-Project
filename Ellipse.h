#pragma once
#include "Point.h"
#include "Figure.h"

class Ellipse : public Figure {
private:
	Point c;
	double rx;
	double ry;
public:
	Ellipse();
	Ellipse(double _cx, double _cy, double _rx, double _ry, std::vector<Property>& _properties);

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);
	void within() const;
};