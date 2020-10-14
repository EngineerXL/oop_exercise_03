#ifndef TRAPEZE_HPP
#define TRAPEZE_HPP

#include "figure.hpp"

class Trapeze : public Figure {
private:
	/* Cords of left bottom corner, larger and smaller base, side */
	long double X, Y, A, B, C;
public:
	Trapeze(const long double & x, const long double & y, const long double & a, const long double & b, const long double & c);
	long double FigureSquare() override;
	Cord FigureCenter() override;
	void FigurePrint() override;
	friend std::ostream & operator << (std::ostream & out, const Trapeze & trapez);
};

#endif /* TRAPEZE_HPP */