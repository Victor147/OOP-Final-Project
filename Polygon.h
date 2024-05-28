#pragma once
#include "Figure.h"

class Polygon : public Figure {
private:
	std::vector<Point> points;
	std::vector<Property> properties;
public:
	Polygon() = default;
	Polygon(std::vector<Point>& _points, std::vector<Property>& _properties);

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);
	void save(std::ostream& out) const;

	std::string getType() const;

	bool contains(const Point& point) const;
	bool within(Figure* fig) const;
	//bool withinRectangle(Figure* rect) const;
	//bool withinCircle(Figure* circle) const;
};