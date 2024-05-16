#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "SVGParser.h"
#include "Menu.h"

void Menu::printHelp() {
	std::cout << "Available commands in this SVG editor:\n"
		<< "1) open <path>;\n"
		<< "2) close*;\n"
		<< "3) save*;\n"
		<< "4) saveas <name>*;\n"
		<< "5) help;\n"
		<< "6) exit.\n"
		<< "* - these are available only after opening a file.\n";
}

void Menu::handleInput() {
	bool isOpened = false;
	SVGParser svg;

	while (true)
	{
		std::string choice, command;
		std::getline(std::cin, choice);

		std::stringstream ss(choice);
		ss >> command;

		if (command == "open" && !isOpened)
		{
			std::string path = choice.substr(choice.find(" ") + 1, choice.size());

			std::ifstream file(path);
			if (!file)
			{
				std::cout << "File not found!\n";
				//continue;
			}
			else {
				//TODO: Print the name of the file rather than just text!
				std::cout << "Successfully opened the file!\n";
				isOpened = true;
				svg.setFile(&file);
				svg.print();
				svg.erase(2);
				svg.print();
				//svg.erase();
				//svg.print();
			}
		}
		//TODO: if when a file is open, to prompt the user if he wants to save the current file before opening a new one
		else if (command == "help")
		{
			printHelp();
		}
		else if (command == "exit")
		{
			return;
		}
		else if (command == "close" || command == "save" || command == "saveas")
		{
			if (!isOpened)
			{
				std::cout << "You need to open a file first!\n";
			}
			else {
				if (command == "close")
				{

				}
				else if (command == "save")
				{

				}
				else if (command == "saveas")
				{

				}
			}
		}
		
		else {
			std::cout << "Invalid command!\n";
		}
	}
}