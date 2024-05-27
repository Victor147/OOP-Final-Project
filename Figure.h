#pragma once
#include <vector>
#include "Property.h"
#include "Point.h"

class Figure {
public:
	std::vector<Property> properties;

	virtual void print(std::ostream& out, size_t ind = -1) const = 0;/*ok*/
	virtual void translate(double horizontal, double vertical) = 0;/*ok*/
	virtual bool contains(const Point& point) const = 0;/*ok*/
	virtual bool within(Figure* fig) const = 0;
	virtual void readFromFile(std::istream& in) = 0;
	virtual void save(std::ostream& out) const = 0;

	static Figure* createFigure(std::string& type, std::vector<Property>& properties);

	friend std::istream& operator>>(std::istream& in, Figure* fig) {
		fig->readFromFile(in);
		return in;
	};
};

//std::istream& operator>>(std::istream& in, Figure* fig) {
//	fig->readFromFile(in);
//	return in;
//}