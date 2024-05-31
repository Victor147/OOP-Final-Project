#pragma once
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Figure.h"

TEST_CASE("Property test") {
	Property empty, fill;
	CHECK((empty.getName() == "" && empty.getValue() == ""));
	std::string nt = "name-test", vt = "value-test";
	fill.setName(nt);
	fill.setValue(vt);

	SUBCASE("Setters test") {
		CHECK((fill.getName() == "name-test" && fill.getValue() == "value-test"));
	}

	fill.insertToValue(nt);
	SUBCASE("InsertToValue test") {
		CHECK(fill.getValue() == "value-testname-test");
	}

	//SUBCASE("Operator== test") {
	//	CHECK((fill == empty) == false);
	//}
	SUBCASE("Operator== test") {
		CHECK((fill == fill) == true);
	}
}

TEST_CASE("Figure factory test") {
	std::vector<Property> props;
	std::string type = "rect";
	Figure* fig = Figure::createFigure(type, props);

	CHECK(fig->getType() == "rectangle");
	SUBCASE("Vector size test") {
		CHECK(fig->properties.size() == 0);
	}

	Property prop1("name1", "value1");
	Property prop2("name2", "value2");
	props.push_back(prop1);
	props.push_back(prop2);

	std::string type2 = "circle";
	Figure* fig2 = Figure::createFigure(type2, props);

	SUBCASE("Vector size test") {
		CHECK(fig2->properties.size() == 2);
	}

	SUBCASE("Contains test") {
		Point p(10, 3);
		CHECK(fig2->contains(p) == false);
	}

	delete fig;
	delete fig2;
}

TEST_CASE("Rectangle test") {
	std::vector<Property> props;
	Property prop1("x", "0");
	Property prop2("y", "0");
	Property prop3("width", "30");
	Property prop4("height", "20");
	props.push_back(prop1);
	props.push_back(prop2);
	props.push_back(prop3);
	props.push_back(prop4);

	std::string type = "rect";

	Figure* fig = Figure::createFigure(type, props);

	SUBCASE("Contains test") {
		Point p(15, 15);
		CHECK(fig->contains(p) == true);
		Point p2(40, 66);
		CHECK(fig->contains(p2) == false);
		Point p3(30, 20);
		CHECK(fig->contains(p3) == true);
	}

	SUBCASE("Within test") {
		Figure* fig2 = Figure::createFigure(type, props);
		CHECK(fig->within(fig2) == true);
		delete fig2;
	}

	SUBCASE("Translate test") {
		fig->translate(10, 10);

		Point p(40, 30);
		CHECK(fig->contains(p));
	}

	delete fig;
}