#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Figure.h"

class SVGParser {
private:
	//std::ifstream* file;
	std::string fileName;
	std::string filePath;
	std::vector<Figure*> figures;

	void loadVector(std::ifstream* file);
public:
	SVGParser();
	//SVGParser(std::ifstream* _file);
	void setFile(std::string& _fileName, std::string& _filePath,  std::ifstream* _file);
	void saveFile();

	void print();
	void erase(size_t ind = -1);
	void translate(double horizontal, double vertical, size_t ind = -1);
	void within(Figure* f);
	void clear();
};