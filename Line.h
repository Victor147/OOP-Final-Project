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

	void print(size_t ind) const;
	void translate(double horizontal, double vertical);
	bool withinRectangle(Figure* rect) const;
	bool withinCircle(Figure* circle) const;
};