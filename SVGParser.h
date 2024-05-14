#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Figure.h"

class SVGParser {
private:
	std::ifstream* file;
	std::vector<Figure*> figures;

	void loadVector();
public:
	SVGParser();
	SVGParser(std::ifstream* _file);
	void setFile(std::ifstream* _file);

	void print();
	void erase(size_t ind = -1);
};