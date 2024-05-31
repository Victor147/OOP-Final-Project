#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Figure.h"

class SVGFile {
private:
	std::string fileName;
	std::string filePath;
	std::vector<Figure*> figures;

	void loadVector(std::ifstream* file);
	void save(std::ofstream& file);
public:
	SVGFile();

	void setFile(std::string& _fileName, std::string& _filePath,  std::ifstream* _file);
	void closeFile();
	void saveFile();
	void saveAsFile(std::string& path);
	
	void print();
	void erase(size_t ind = -1);
	void addFigure(Figure* f);
	void translate(double horizontal, double vertical, size_t ind = -1);
	void within(Figure* f);

	~SVGFile();
};