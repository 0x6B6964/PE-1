#pragma once
#include "FunctionContainer.h"

class QuadraticFunction : public FunctionContainer
{
private:
	double _a;
	double _b;
	double _c;

public:
	QuadraticFunction(double a, double b, double c) {
		_a = a;
		_b = b;
		_c = c;
	}
	double ComputeWith(double x) override;
	std::string ToString() override;
};