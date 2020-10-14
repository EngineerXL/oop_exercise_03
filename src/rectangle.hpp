#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "figure.hpp"

class Rectangle : public Figure {
private:
	/* Cords of left bottom corner, width and height */
	long double X, Y, A, B;
public:
	Rectangle(const long double & x, const long double & y, const long double & a, const long double & b);
	long double FigureSquare() override;
	Cord FigureCenter() override;
	void FigurePrint() override;
	friend std::ostream & operator << (std::ostream & out, const Rectangle & rect);
};

#endif /* RECTANGLE_HPP */