#include <sstream>
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Ellipse.h"
#include "Polyline.h"
#include "Polygon.h"

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
	else if (type == "circle")
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
	else if (type == "line")
	{
		double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		std::vector<Property> cut;

		for (Property p : properties) {
			if (p.getName() == "x1")
			{
				x1 = std::stod(p.getValue());
			}
			else if (p.getName() == "y1")
			{
				y1 = std::stod(p.getValue());
			}
			else if (p.getName() == "x2")
			{
				x2 = std::stod(p.getValue());
			}
			else if (p.getName() == "y2")
			{
				y2 = std::stod(p.getValue());
			}
			else {
				cut.push_back(p);
			}
		}

		return new Line(x1, y1, x2, y2, cut);
	}
	else if (type == "ellipse") {
		double cx = 0, cy = 0, rx = 0, ry = 0;
		std::vector<Property> cut;

		for (Property p : properties) {
			if (p.getName() == "cx")
			{
				cx = std::stod(p.getValue());
			}
			else if (p.getName() == "cy")
			{
				cy = std::stod(p.getValue());
			}
			else if (p.getName() == "rx")
			{
				rx = std::stod(p.getValue());
			}
			else if (p.getName() == "ry")
			{
				ry = std::stod(p.getValue());
			}
			else {
				cut.push_back(p);
			}
		}

		return new Ellipse(cx, cy, rx, ry, cut);
	}
	else if (type == "polyline" || type == "polygon") {
		std::vector<Point> points;
		std::vector<Property> cut;

		for (Property p : properties) {
			if (p.getName() == "points")
			{
				std::string pointsStr = p.getValue(), word;
				std::istringstream iss(pointsStr);

				double x = 0, y = 0;
				while (iss >> word)
				{
					if (word.find(",") == std::string::npos)
					{
						y = std::stod(word);
						Point p(x, y);
						points.push_back(p);
					}
					else {
						if (word.find(",") == word.size() - 1)
						{
							x = std::stod(word.substr(0, word.find(",")));
						}
						else {
							double xt = std::stod(word.substr(0, word.find(",")));
							double yt = std::stod(word.substr(word.find(",") + 1, word.size() - word.find(",")));
							Point p(xt, yt);
							points.push_back(p);
						}
					}
				}
			}
			else {
				cut.push_back(p);
			}
		}

		if (type == "polyline")
		{
			return new Polyline(points, cut);
		}
		return new Polygon(points, cut);
	}
}
