#include <string>
#include <regex>
#include <sstream>
#include <iostream>
#include "SVGParser.h"
#include "Figure.h"

SVGParser::SVGParser() {}

void SVGParser::save(std::ofstream& file) {
	file << "<svg>\n";
	for (Figure* f : figures) {
		f->save(file);
	}
	file << "</svg>\n";

	file.close();
}

void SVGParser::closeFile() {
	fileName = "";
	filePath = "";
	for (size_t i = 0; i < figures.size(); i++)
	{
		delete figures[i];
	}
	figures.clear();

	std::cout << "Closing the file...\n";
}

void SVGParser::setFile(std::string& _fileName, std::string& _filePath, std::ifstream* _file) {
	fileName = _fileName;
	filePath = _filePath;
	loadVector(_file);
}

void SVGParser::saveFile() {
	std::ofstream file(filePath);
	save(file);
	std::cout << "Successfully saved the changes to " << fileName << "!\n";
}

void SVGParser::print() {
	if (figures.size() == 0)
	{
		std::cout << "There are no figures!\n";
	}
	else {
		for (int i = 0; i < figures.size(); ++i) {
			figures[i]->print(std::cout, i + 1);
		}
	}
}

void SVGParser::erase(size_t ind) {
	if (ind == -1)
	{
		figures.clear();
		std::cout << "Erased all figures!\n";
	}
	else {
		--ind;
		if (ind < 0 || ind >= figures.size())
		{
			std::cout << "There is no figure number " << ind + 1 << "!\n";
		}
		else {
			std::cout << "Erased a " << figures[ind]->getType() << "! (" << ind + 1 << ")\n";
			figures.erase(figures.begin() + ind);
		}
	}
}

void SVGParser::addFigure(Figure* f) {
	figures.push_back(f);
	std::cout << "Successfully created a " << f->getType() << "! (" << figures.size() << ")\n";
}

void SVGParser::translate(double horizontal, double vertical, size_t ind) {
	if (ind == -1)
	{
		for (Figure* f : figures)
		{
			f->translate(horizontal, vertical);
		}

		std::cout << "Translated all figures!" << std::endl;
	}
	else {
		--ind;
		if (ind < 0 || ind >= figures.size())
		{
			std::cout << "There is no figure number " << ind + 1 << "!" << std::endl;
		}
		else {
			Figure* f = figures[ind];
			f->translate(horizontal, vertical);
			std::cout << "Translated a " << f->getType() << "! (" << ++ind << ")\n";
		}
	}
}

void SVGParser::loadVector(std::ifstream* file) {
	std::string str, result = "";
	bool flag = false;

	while (*file)
	{
		*file >> str;
		if (str == "<svg>" || str == "<svg")
		{
			flag = true;
			result += str += " ";
		}
		else if (str == "</svg>" && flag) {
			flag = false;
			result += str;
		}
		else if (flag == true) {
			result += str += " ";
		}
	}

	std::regex regexp("<[^>]+\/>");
	std::smatch match;

	std::vector<std::string> lines;

	while (std::regex_search(result, match, regexp)) {
		lines.push_back(match[0]);

		// suffix to find the rest of the string.
		result = match.suffix().str();
	}

	for (std::string l : lines) {
		std::string type = l.substr(l.find("<") + 1, l.find(" ") - 1);
		Property p;

		std::vector<Property> properties;

		std::istringstream iss(l);
		std::string word;
		bool waitForQuote = false;

		while (iss >> word)
		{
			if (word.find("=") != std::string::npos)
			{
				std::string propName = word.substr(0, word.find("="));
				std::string propValue;
				if (word[word.size() - 1] == '"')
				{
					propValue = word.substr(word.find("=") + 2, word.size() - word.find("=") - 3);
				}
				else {
					propValue = word.substr(word.find("=") + 2, word.size() - word.find("=") - 2);
				}

				if (propName == "points" || propName == "d")
				{
					waitForQuote = true;
				}
				p.setName(propName);
				p.setValue(propValue);
			}
			else {
				if (waitForQuote)
				{
					if (word.find("\"") == std::string::npos)
					{
						std::string add = " " + word;
						p.insertToValue(add);
					}
					else {
						std::string temp = " " + word.substr(0, word.find("\""));
						p.insertToValue(temp);
						waitForQuote = false;
					}
				}
			}

			if (p.getName() != "" && p.getValue() != "" && !std::count(properties.begin(), properties.end(), p) && !waitForQuote)
			{
				properties.push_back(p);
			}
		}

		Figure* f = Figure::createFigure(type, properties);

		if (f != nullptr)
		{
			figures.push_back(f);
		}
	}
}

void SVGParser::within(Figure* f) {
	int k = 1;
	for (Figure* fig : figures) {
		if (fig->within(f))
		{
			fig->print(std::cout, k);
			++k;
		}
	}
	if (k == 1)
	{
		std::cout << "No figures are located within ";
		f->print(std::cout);
	}
}

void SVGParser::saveAsFile(std::string& path) {
	std::ofstream file(path);
	save(file);
}

SVGParser::~SVGParser() {
	for (Figure* f : figures) {
		delete f;
	}
}