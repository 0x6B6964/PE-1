#pragma once
#include <string>

class FunctionContainer
{
public:
	FunctionContainer() { };

	virtual double ComputeWith(double x) = 0;
	virtual std::string ToString() = 0;
};