#pragma once
#include <vector>
#include "Figure.h"

class Circle : public Figure {
private:
	Point c;
	double r;
public:
	Circle();
	Circle(double _x, double _y, double _r, std::vector<Property>& _properties);

	void print(size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream&);

	bool contains(const Point& p) const;
	bool within(Figure*) const;

	Point& getCenter();
	double getRadius();
};