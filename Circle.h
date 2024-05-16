#pragma once
#include "Point.h"
#include "Figure.h"

class Circle : public Figure
{
private:
	Point c;
	double r;
public:
	Circle();
	Circle(double _x, double _y, double _r, std::vector<Property>& _properties);

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);
	void within() const;
};