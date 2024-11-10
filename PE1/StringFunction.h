#pragma once
#include "FunctionContainer.h"
#include <string>

using namespace std;

class StringFunction : public FunctionContainer
{
private:
	string _stringFunction;

public:
	StringFunction(string SelectedFunction) {
		_stringFunction = SelectedFunction;
		ToLowerCase(_stringFunction);
	}

	float ComputeWith(float x) override;
	std::string ToString() override;

	static float ParseFunctionAndYieldResult(const string function, float x);

	/// <summary>
	/// Changes every letter in string to lowercase (by reference)
	/// </summary>
	static int ToLowerCase(string& str);
};

