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

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);
	void save(std::ostream& out) const;

	std::string getType() const;

	bool contains(const Point& point) const;
	bool within(Figure* fig) const;

	double length() const;
};
