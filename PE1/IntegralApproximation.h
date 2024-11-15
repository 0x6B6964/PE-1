#pragma once
#include "FunctionContainer.h"
#include "LinearFunction.h"

class IntegralApproximation
{
private:
	double _a;
	double _b;
	FunctionContainer* _selectedFunction;

public: 
	IntegralApproximation(double a, double b, FunctionContainer* functionToCompute) {
		_a = a;
		_b = b;

		_selectedFunction = functionToCompute;
	}

	/// <returns> Returns range of integration </returns>
	double GetRange();

	/// <summary>
	/// Finds approximate value of integration, using trapezoid method
	/// </summary>
	/// <param name="n"> Number of trapesoids </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithTrapesoid(unsigned int n);
};

