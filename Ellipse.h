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

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);
	void save(std::ostream& out) const;

	std::string getType() const;
	
	bool contains(const Point& point) const;
	bool within(Figure* figure) const;
};