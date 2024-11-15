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

#pragma region Integral approximations

	/// <summary>
	/// Finds approximate value of integration, using left rectangles method
	/// </summary>
	/// <param name="n"> Number of rectangles </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithLeftRectangles(unsigned int n);

	/// <summary>
	/// Finds approximate value of integration, using midpoint rectangles method
	/// </summary>
	/// <param name="n"> Number of rectangles </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithMidpointRectangles(unsigned int n);

	/// <summary>
	/// Finds approximate value of integration, using left rectangles method
	/// </summary>
	/// <param name="n"> Number of rectangles </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithRightRectangles(unsigned int n);

	/// <summary>
	/// Finds average of all the rectangle approximations, decreasing inaccuracy varience, but increasing average inaccuracy
	/// </summary>
	/// <param name="n"> Number of rectangles </param>
	/// <returns></returns>
	inline double IntegrateWithAllRectangles(unsigned int n) { return (IntegrateWithLeftRectangles(n) + IntegrateWithMidpointRectangles(n) + IntegrateWithRightRectangles(n)) / 3; }

	/// <summary>
	/// Finds approximate value of integration, using trapezoid method
	/// </summary>
	/// <param name="n"> Number of trapesoids </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithTrapesoid(unsigned int n);

	/// <summary>
	/// Finds approximate value of integration, using paraboles method (Simpson rule)
	/// </summary>
	/// <param name="n"> Number of parabole spans </param>
	/// <returns> Approximate value of integration of selected function </returns>
	double IntegrateWithParabole(unsigned int n);

	/// <summary>
	/// Finds approximate value of integration, using Simpson rule (paraboles method)
	/// </summary>
	/// <param name="n"> Number of parabole spans </param>
	/// <returns> Approximate value of integration of selected function </returns>
	inline double IntegrateWithSimpsonRule(unsigned int n) { return IntegrateWithParabole(n); }

#pragma endregion

};

