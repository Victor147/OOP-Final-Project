#include <iostream>
#include "Property.h"

Property::Property(std::string _name, std::string _value) : name(_name), value(_value) {}

void Property::print(std::ostream& out) const {
	out << " " << value;
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

void Property::save(std::ostream& out) const {
	out << " " << name << "=\"" << value << "\"";
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