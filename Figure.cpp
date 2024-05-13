#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"

Figure* Figure::createFigure(std::string& type, std::vector<Property>& properties) {
	if (type == "rect")
	{
		double x = 0, y = 0, width = 0, height = 0;
		std::vector<Property> cut;
		
		for (Property p : properties)
		{
			if (p.getName() == "x")
			{
				x = std::stod(p.getValue());
			}
			else if (p.getName() == "y")
			{
				y = std::stod(p.getValue());
			}
			else if (p.getName() == "width")
			{
				width = std::stod(p.getValue());
			}
			else if (p.getName() == "height")
			{
				height = std::stod(p.getValue());
			}
			else {
				cut.push_back(p);
			}
		}

		return new Rectangle(x, y, width, height, cut);
	}
	if (type == "circle")
	{
		double x = 0, y = 0, r = 0;
		std::vector<Property> cut;

		for (Property p : properties) {
			if (p.getName() == "cx")
			{
				x = std::stod(p.getValue());
			}
			else if (p.getName() == "cy")
			{
				y = std::stod(p.getValue());
			}
			else if (p.getName() == "r")
			{
				r = std::stod(p.getValue());
			}
			else {
				cut.push_back(p);
			}
		}

		return new Circle(x, y, r, cut);
	}
}
