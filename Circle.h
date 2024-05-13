#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	double x;
	double y;
	double r;
public:
	Circle();
	Circle(double _x, double _y, double _r, std::vector<Property>& _properties);

	void print() const;
	//void create();
	void translate(size_t ind = -1);
	void within() const;
	void loadFigure(/*???*/);
};