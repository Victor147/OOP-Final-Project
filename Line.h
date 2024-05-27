#pragma once
#include "Point.h"
#include "Figure.h"

class Line : public Figure {
private:
	Point p1;
	Point p2;
public:
	Line();
	Line(double _x1, double _y1, double _x2, double _y2, std::vector<Property>& _properties);

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);
	void save(std::ostream& out) const;

	bool contains(const Point& p) const;
	bool within(Figure* fig) const;
	//bool withinRectangle(Figure* rect) const;
	//bool withinCircle(Figure* circle) const;
};