#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Figure.h"

class SVGParser {
private:
	//std::ifstream* file;
	std::vector<Figure*> figures;

	void loadVector(std::ifstream* file);
public:
	SVGParser();
	//SVGParser(std::ifstream* _file);
	void setFile(std::ifstream* _file);

	void print();
	void erase(size_t ind = -1);
	void translate(double horizontal, double vertical, size_t ind = -1);
	void within(Figure* f);
};