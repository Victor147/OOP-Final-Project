#pragma once
#include "Figure.h"
#include "Point.h"

class Polygon : public Figure {
private:
	std::vector<Point> points;
	std::vector<Property> properties;
public:
	Polygon() = default;
	Polygon(std::vector<Point>& _points, std::vector<Property>& _properties);

	void print(size_t ind) const;
	//void create();
	void translate(size_t ind = -1);
	void within() const;
	void loadFigure(/*???*/);
};