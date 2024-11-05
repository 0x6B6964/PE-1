#pragma once
#include "FunctionContainer.h"

class QuadraticFunction : public FunctionContainer
{
private:
	float _a;
	float _b;
	float _c;

public:
	QuadraticFunction(float a, float b, float c) {
		_a = a;
		_b = b;
		_c = c;
	}
	float ComputeWith(float x) override;
	std::string ToString() override;
};