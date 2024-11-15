#pragma once
#include "FunctionContainer.h"

class LinearFunction : public FunctionContainer
{
private:
	double _k;
	double _b;

public:
	LinearFunction(double k, double b) {
		_k = k;
		_b = b;
	}
	double ComputeWith(double x) override;
	std::string ToString() override;
};