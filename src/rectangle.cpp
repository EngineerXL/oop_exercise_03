#include "rectangle.hpp"

Rectangle::Rectangle(const long double & x, const long double & y, const long double & a, const long double & b) : X(x), Y(y), A(a), B(b) {
	if (A < 0.0 or B < 0.0) {
		throw std::invalid_argument("Invalid rectangle parameters!");
	}
};

long double Rectangle::FigureSquare() {
	return A * B;
}

Cord Rectangle::FigureCenter() {
	return Cord(X + A / 2.0, Y + B / 2.0);
}

void Rectangle::FigurePrint() {
	std::cout << *this << std::endl;
}

std::ostream & operator << (std::ostream & out, const Rectangle & rectangle) {
	out << "Rectangle verticies: [";
	out << Cord(rectangle.X, rectangle.Y) << ", ";
	out << Cord(rectangle.X, rectangle.Y + rectangle.B) << ", ";
	out << Cord(rectangle.X + rectangle.A, rectangle.Y + rectangle.B) << ", ";
	out << Cord(rectangle.X + rectangle.A, rectangle.Y);
	out << "]";
	return out;
}
