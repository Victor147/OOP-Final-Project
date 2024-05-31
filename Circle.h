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

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream&);
	void save(std::ostream& out) const;

	std::string getType() const;

	bool contains(const Point& p) const;
	bool within(Figure*) const;

	double area() const;
	double perimeter() const;

	Point& getCenter();
	double getRadius();
};