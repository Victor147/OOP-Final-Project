#include <iostream>
#include "Property.h"

void Property::print() const {
	std::cout << " " << value;
}

void Property::setName(std::string& _name) {
	name = _name;
}

void Property::setValue(std::string& _value) {
	value = _value;
}

void Property::insertToValue(std::string& _value) {
	value += _value;
}

std::string& Property::getName() {
	return name;
}

std::string& Property::getValue() {
	return value;
}

bool Property::operator==(const Property& other) const {
	return name == other.name && value == other.value;
}