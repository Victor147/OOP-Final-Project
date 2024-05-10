#pragma once

class Figure {
	virtual void print() = 0;
	virtual void create() = 0;
	void remove();
	virtual void translate(size_t ind = -1) = 0;
	virtual void within() = 0;
	virtual void loadFigure() = 0;
};
