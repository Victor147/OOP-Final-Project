#pragma once

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

	void print() const;
};