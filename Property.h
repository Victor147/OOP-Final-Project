#pragma once
#include <string>

class Property {
private:
	std::string name;
	std::string value;
public:
	Property() = default;
	Property(std::string _name, std::string _value);

	void print(std::ostream& out) const;
	void setName(std::string& _name);
	void setValue(std::string& _value);
	void save(std::ostream& out) const;

	std::string& getName();
	std::string& getValue();

	void insertToValue(std::string& _value);

	bool operator==(const Property& other) const;
};
