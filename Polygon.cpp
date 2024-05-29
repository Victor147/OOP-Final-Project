#include <iostream>
#include "Polygon.h"

Polygon::Polygon(std::vector<Point>& _points, std::vector<Property>& _properties) {
	for (Point p : _points) {
		points.push_back(p);
	}
	for (Property p : _properties) {
		properties.push_back(p);
	}
}

void Polygon::print(std::ostream& out, size_t ind) const {
	if (ind == -1)
	{
		out << "polygon - ";
	}
	else {
		out << ind << ". polygon -";
	}

	for (size_t i = 0; i < points.size(); ++i) {
		points[i].print(out);
		if (i != points.size() - 1)
		{
			out << ",";
		}
	}

	for (Property p : properties) {
		p.print(out);
	}

	out << std::endl;
}

void Polygon::translate(double horizontal, double vertical) {
	for (Point& p : points) {
		p.translate(horizontal, vertical);
	}
}

void Polygon::readFromFile(std::istream& in) {
	int isPoint = 0, countWords = 0;
	std::string value;
	double x = 0, y = 0;
	while (in >> value) {
		if (isdigit(value[0]))
		{
			if (isPoint == 0) {
				x = stoi(value);
				++isPoint;
			}
			else if (isPoint == 1) {
				y = stoi(value);
				Point p(x, y);
				points.push_back(p);
				isPoint = 0;
				x = 0;
				y = 0;
			}
		}
		else {
			if (countWords == 0)
			{
				Property p("fill", value);
				properties.push_back(p);
				++countWords;
			}
			else if (countWords == 1) {
				Property p("stroke", value);
				properties.push_back(p);
				++countWords;
			}
		}
	}
}

void Polygon::save(std::ostream& out) const {
	out << "<polygon points=\"";
	for (size_t i = 0; i < points.size(); ++i) {
		points[i].save(out);
		if (i != points.size() - 1)
		{
			out << " ";
		}
	}
	out << "\"";
	for (Property p : properties) {
		p.save(out);
	}
	out << " />\n";
}

std::string Polygon::getType() const {
	return "polygon";
}

bool Polygon::contains(const Point& p) const {
	return false;
}

bool Polygon::within(Figure* fig) const {
	for (Point p : points) {
		if (!fig->contains(p)) {
			return false;
		}
	}
	return true;
}