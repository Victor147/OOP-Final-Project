#pragma once
#include <string>

//template <typename T>
class Property {
private:
	std::string name;
	std::string value;
public:
	void print() const;
	void setName(std::string& _name);
	void setValue(std::string& _value);

	std::string& getName();
	std::string& getValue();

	void insertToValue(std::string& _value);

	bool operator==(const Property& other) const;
};
