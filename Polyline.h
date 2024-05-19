#pragma once
#include "Point.h"
#include "Figure.h"

class Polyline : public Figure {
private:
	std::vector<Point> points;
	std::vector<Property> properties;
public:
	Polyline() = default;
	Polyline(std::vector<Point>& _points, std::vector<Property>& _properties);

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);

	bool contains(const Point& point) const;
	bool within(Figure* fig) const;
	//bool withinRectangle(Figure* rect) const;
	//bool withinCircle(Figure* circle) const;
};
