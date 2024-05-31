#pragma once
#include <sstream>

class Point {
private:
	double x;
	double y;
public:
	Point();
	Point(double _x, double _y);

	double getX() const;
	double getY() const;

	void setX(double _x);
	void setY(double _y);

	void translate(double horizontal, double vertical);

	void print(std::ostream& out) const;
	void save(std::ostream& out) const;

	double distance(const Point& point) const;

	friend std::istream& operator>>(std::istream& in, Point& instance)
	{
		in >> instance.x;
		in >> instance.y;

		return in;
	};
};

//std::istream& operator>>(std::istream& in, Point& instance) {
//	float x = 0, y = 0;
//	in >> x;
//	in >> y;
//
//	instance.setX(x);
//	instance.setY(y);
//	return in;
//};