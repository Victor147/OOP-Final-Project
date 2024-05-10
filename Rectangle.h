#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);

	void print() const;
	//void create();
	void translate(size_t ind = -1);
	void within() const;
private:
	double x;
	double y;
    double width;
    double length;
};