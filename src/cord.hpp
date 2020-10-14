#ifndef CORD_HPP
#define CORD_HPP

#include <bits/stdc++.h>

struct Cord {
protected:
	long double X, Y;
public:
	Cord() : X(NAN), Y(NAN) {};
	Cord(long double x, long double y) : X(x), Y(y) {};
	~Cord() {};
	friend std::ostream & operator << (std::ostream & out, const Cord & crd);
};

#endif /* CORD_HPP */