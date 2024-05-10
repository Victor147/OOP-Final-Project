#pragma once
#include <string>
#include <vector>
#include "Figure.h"

class SVGParser {
private:
	std::string fileName;
	std::vector<Figure*> figures;

	void loadFigures();
public:
	SVGParser(std::string _fileName);
};