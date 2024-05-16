#pragma once
#include <vector>
#include "Property.h"


class Figure {
public:
	std::vector<Property> properties;

	virtual void print(size_t ind) const = 0;/*ok*/
	virtual void translate(double horizontal, double vertical) = 0;/*ok*/
	virtual void within() const = 0;
	//virtual void loadFigure(/*???*/) = 0;

	static Figure* createFigure(std::string& type, std::vector<Property>& properties);
};
