#include "QuadraticFunction.h"
#include <string>

double QuadraticFunction::ComputeWith(double x) {
	return _a * x * x + _b * x + _c;
}

std::string QuadraticFunction::ToString() {
	return "y = " + std::to_string(_a) + "x^2 + " + std::to_string(_b) + "x + " + std::to_string(_c);
}
