#pragma once
#include "Point.h"
#include "Figure.h"

class Polygon : public Figure {
private:
	std::vector<Point> points;
	std::vector<Property> properties;
public:
	Polygon() = default;
	Polygon(std::vector<Point>& _points, std::vector<Property>& _properties);

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);

	bool withinRectangle(Figure* rect) const;
	bool withinCircle(Figure* circle) const;
};