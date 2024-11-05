#pragma once
#include <string>

class FunctionContainer
{
public:
	FunctionContainer() { };

	virtual float ComputeWith(float x) = 0;
	virtual std::string ToString() = 0;
};