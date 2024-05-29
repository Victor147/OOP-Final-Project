#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "SVGParser.h"
#include "Menu.h"

void Menu::printHelp() {
	std::cout << "Available commands in this SVG editor:\n"
		<< "1) open <path>;\n"
		<< "2) print*;\n/"
		<< "3) create <figure>*;\n"
		<< "4) erase [<index>]*;\n"
		<< "5) translate <horizontal> <vertical> [<index>]*;\n"
		<< "6) within <figure>*;\n"
		<< "7) close*;\n"
		<< "8) save*;\n"
		<< "9) saveas <name>*;\n"
		<< "10) help;\n"
		<< "11) exit.\n"
		<< "* - these are available only after opening a file.\n";
}

void Menu::handleInput() {
	bool isOpened = false, specialCase = false;
	SVGParser svg;

	while (true)
	{
		std::string choice, command;
		std::getline(std::cin, choice);

		std::stringstream ss(choice);
		ss >> command;

		if (command == "open")
		{
			if (!isOpened)
			{
				std::string path = choice.substr(choice.find(" ") + 1, choice.size());

				std::ifstream file(path);
				if (!file)
				{
					std::cout << "File not found! Try again!\n";
				}
				else {
					std::string fileName;
					if (path.find("\\") == std::string::npos)
					{
						fileName = path;
					}
					else {
						fileName = path.substr(path.find_last_of("\\") + 1, path.size());
					}

					std::cout << "Successfully opened " << fileName << "!\n";
					isOpened = true;
					svg.setFile(fileName, path, &file);
				}

			}
			else {
				std::cout << "You have already opened a file!\n";
			}
		}
		else if (command == "help")
		{
			printHelp();
		}
		else if (command == "exit")
		{
			std::cout << "Exiting the program...\n";
			return;
		}
		else if (command == "close" || command == "save" || command == "saveas" ||
			command == "within" || command == "translate" || command == "erase" ||
			command == "create" || command == "print")
		{
			if (!isOpened)
			{
				std::cout << "You need to open a file first!\n";
			}
			else {
				if (command == "close")
				{
					std::cout << "Do you want to save the file before closing it? (y/n)\n";
					char choice;
					std::cin >> choice;
					std::cin.ignore();
					if (choice == 'y')
					{
						svg.saveFile();
					}

					svg.closeFile();
					isOpened = false;
				}
				else if (command == "save")
				{
					svg.saveFile();
				}
				else if (command == "saveas")
				{
					std::string savePath;
					ss >> savePath;

					svg.saveAsFile(savePath);
				}
				else if (command == "print" && isOpened)
				{
					svg.print();
				}
				else if (command == "create" && isOpened)
				{
					std::string figureType;
					ss >> figureType;

					figureType = figureType == "rectangle" ? "rect" : figureType;

					std::vector<Property> props;

					Figure* f = Figure::createFigure(figureType, props);

					ss >> f;
					svg.addFigure(f);
				}
				else if (command == "erase" && isOpened) {
					std::string ind;
					if (ss >> ind)
						svg.erase(std::stoi(ind));
					else {
						svg.erase();
					}
				}
				else if (command == "translate" && isOpened) {
					std::string first, second, ind;
					double horizontal = 0, vertical = 0;
					ss >> first;
					ss >> second;

					std::string fLHand = first.substr(0, first.find("="));
					std::string sLHand = second.substr(0, second.find("="));
					if (fLHand == "horizontal")
					{
						horizontal = std::stod(first.substr(first.find("=") + 1, first.size()));
					}
					else if (fLHand == "vertical")
					{
						vertical = std::stod(first.substr(first.find("=") + 1, first.size()));
					}
					if (sLHand == "horizontal")
					{
						horizontal = std::stod(second.substr(second.find("=") + 1, second.size()));
					}
					else if (sLHand == "vertical")
					{
						vertical = std::stod(second.substr(second.find("=") + 1, second.size()));
					}

					if (ss >> ind)
					{
						svg.translate(horizontal, vertical, std::stoi(ind));
					}
					else {
						svg.translate(horizontal, vertical);
					}
				}
				else if (command == "within" && isOpened)
				{
					std::string type;
					ss >> type;

					std::vector<Property> props;

					Figure* f = Figure::createFigure(type, props);
					ss >> f;

					svg.within(f);
				}
			}
		}
		else {
			std::cout << "Invalid command!\n";
		}
	}
}