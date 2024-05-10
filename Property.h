#pragma once
#include <string>

//template <typename T>
class Property {
private:
	std::string name;
	std::string value;
public:
	void print() const;
};
