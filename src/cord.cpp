#include "cord.hpp"

std::ostream & operator << (std::ostream & out, const Cord & crd) {
	out << "(" << crd.X << ", " << crd.Y << ")";
	return out;
}