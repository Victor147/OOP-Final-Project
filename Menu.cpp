#include "Menu.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
	while (true)
	{
		std::string choice, command;
		std::getline(std::cin, choice);

		std::stringstream ss(choice);
		ss >> command;

		if (command == "open")
		{
			std::string path = choice.substr(choice.find(" ") + 1, choice.size());

			std::ifstream file(path);
			if (!file)
			{
				std::cout << "File not found!\n";
				continue;
			}
			else {
				//TODO: Print the name of the file rather than just text!
				std::cout << "Successfully opened the file!\n";
			}
		}
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
			std::cout << "You need to open a file first!\n";
		}
		else {
			std::cout << "Invalid command!\n";
		}
	}
}