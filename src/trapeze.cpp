#include "trapeze.hpp"

Trapeze::Trapeze(const long double & x, const long double & y, const long double & a, const long double & b, const long double & c) : X(x), Y(y), A(a), B(b), C(c) {
	if (A < 0.0 or B < 0.0 or C < 0.0) {
		throw std::invalid_argument("Invalid trapeze parameters!");
	}
	if (B > A) {
		std::swap(A, B);
	}
};

long double Trapeze::FigureSquare() {
	long double diff = (A - B) / 2.0;
	long double height = std::sqrt(C * C - diff * diff);
	return height * (A + B) / 2.0;
}

Cord Trapeze::FigureCenter() {
	long double diff = (A - B) / 2.0;
	long double height = std::sqrt(C * C - diff * diff);
	return Cord(X + A / 2.0, Y + height / 2.0);
}

void Trapeze::FigurePrint() {
	std::cout << *this << std::endl;
}

std::ostream & operator << (std::ostream & out, const Trapeze & trapeze) {
	long double diff = (trapeze.A - trapeze.B) / 2.0;
	long double height = std::sqrt(trapeze.C * trapeze.C - diff * diff);
	out << "Trapeze verticies: [";
	out << Cord(trapeze.X, trapeze.Y) << ", ";
	out << Cord(trapeze.X + diff, trapeze.Y + height) << ", ";
	out << Cord(trapeze.X + trapeze.A - diff, trapeze.Y + height) << ", ";
	out << Cord(trapeze.X + trapeze.A, trapeze.Y);
	out << "]";
	return out;
}
