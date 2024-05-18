#pragma once
#include <vector>
#include "Figure.h"
#include "Point.h"

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

	bool withinRectangle(Figure* rect) const;
	bool withinCircle(Figure* circle) const;

	Point& getCenter();
	double getRadius();

	bool contains(const Point& point) const;
};