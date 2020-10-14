#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "figure.hpp"

class Square : public Figure {
private:
	/* Cords of left bottom corner, side */
	long double X, Y, A;
public:
	Square(const long double & x, const long double & y, const long double & a);
	long double FigureSquare() override;
	Cord FigureCenter() override;
	void FigurePrint() override;
	friend std::ostream & operator << (std::ostream & out, const Square & sq);
};

#endif /* SQUARE_HPP */