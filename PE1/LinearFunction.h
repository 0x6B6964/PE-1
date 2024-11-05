#pragma once
#include "FunctionContainer.h"

class LinearFunction : public FunctionContainer
{
private:
	float _k;
	float _b;

public:
	LinearFunction(float k, float b) {
		_k = k;
		_b = b;
	}
	float ComputeWith(float x) override;
	std::string ToString() override;
};