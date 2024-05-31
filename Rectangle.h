#pragma once
#include <vector>
#include "Figure.h"

class Rectangle : public Figure {
private:
	Point p;
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double _x, double _y, double _width, double _height);
	Rectangle(double _x, double _y, double _width, double _height, std::vector<Property>& _properties);

	void print(std::ostream& out, size_t ind = -1) const;
	void translate(double horizontal, double vertical);
	void readFromFile(std::istream& in);
	void save(std::ostream& out) const;

	std::string getType() const;

	bool contains(const Point& point) const;
	bool within(Figure* fig) const;

	double area() const;
	double perimeter() const;

	Point& getPoint();
	double getWidth();
	double getHeight();
};