#pragma once
#include "Point.h"
#include "Figure.h"

class Polyline : public Figure {
private:
	std::vector<Point> points;
public:
	Polyline() = default;
	Polyline(std::vector<Point>& _points, std::vector<Property>& _properties);

	void print(size_t ind) const;
	//void create();
	void translate(size_t ind = -1);
	void within() const;
	void loadFigure(/*???*/);
};
