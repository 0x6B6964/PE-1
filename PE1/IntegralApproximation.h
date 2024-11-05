#pragma once
#include "FunctionContainer.h"
#include "LinearFunction.h"

class IntegralApproximation
{
private:
	float _a;
	float _b;
	FunctionContainer* _selectedFunction;

public: 
	IntegralApproximation(float a, float b, FunctionContainer* functionToCompute) {
		_a = a;
		_b = b;

		_selectedFunction = functionToCompute;
	}

	/// <returns> Returns range of integration </returns>
	float GetRange();

	/// <summary>
	/// Finds approximate value of integration, using trapezoid method
	/// </summary>
	/// <param name="n"> Number of trapesoids </param>
	/// <returns> Approximate value of integration of selected function </returns>
	float IntegrateWithTrapesoid(int n);
};

