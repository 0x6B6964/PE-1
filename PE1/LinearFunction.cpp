#include "LinearFunction.h"
#include <string>

float LinearFunction::ComputeWith(float x) {
	return _k * x + _b;
}

std::string LinearFunction::ToString() {
	if (_k == 0)
		return "y = " + std::to_string(_b);

	if (_b == 0)
		return "y = " + std::to_string(_k) + "x";

	return "y = " + std::to_string(_k) + "x + " + std::to_string(_b);
}