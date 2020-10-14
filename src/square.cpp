#include "square.hpp"

Square::Square(const long double & x, const long double & y, const long double & a) : X(x), Y(y), A(a) {
	if (A < 0.0) {
		throw std::invalid_argument("Invalid square parameters!");
	}
}

long double Square::FigureSquare() {
	return A * A;
}

Cord Square::FigureCenter() {
	return Cord(X + A / 2.0, Y + A / 2.0);
}

void Square::FigurePrint() {
	std::cout << *this << std::endl;
}

std::ostream & operator << (std::ostream & out, const Square & square) {
	out << "Square verticies: [";
	out << Cord(square.X, square.Y) << ", ";
	out << Cord(square.X, square.Y + square.A) << ", ";
	out << Cord(square.X + square.A, square.Y + square.A) << ", ";
	out << Cord(square.X + square.A, square.Y);
	out << "]";
	return out;
}