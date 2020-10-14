#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "cord.hpp"

class Figure {
public:
	virtual long double FigureSquare() = 0;
	virtual Cord FigureCenter() = 0;
	virtual void FigurePrint() = 0;
};

#endif /* FIGURE_HPP */