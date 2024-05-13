#include <string>
#include <regex>
#include <sstream>
#include "SVGParser.h"
#include "Figure.h"

SVGParser::SVGParser() {
	file = nullptr;
}

SVGParser::SVGParser(std::ifstream* _file) : file(_file) {
	loadVector();
}

void SVGParser::setFile(std::ifstream* _file) {
	file = _file;
	loadVector();
}

void SVGParser::print() {
	for (Figure* f : figures) {
		f->print();
	}
}

void SVGParser::loadVector() {
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
		//Figure* f = Figure::createFigure(type);
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
				std::string propValue = word.substr(word.find("=") + 2, word.size() - word.find("=")- 3);
			
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
						std::string temp = " " + word.substr(0, word.find("\"") + 1);
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