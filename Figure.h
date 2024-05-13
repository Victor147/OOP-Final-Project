#pragma once
#include <vector>
#include "Property.h"


class Figure {
public:
	std::vector<Property> properties;

	virtual void print() const = 0;
	//virtual void create() = 0;
	virtual void translate(size_t ind = -1) = 0;
	virtual void within() const = 0;
	virtual void loadFigure(/*???*/) = 0;

	static Figure* createFigure(std::string& type, std::vector<Property>& properties);
};
