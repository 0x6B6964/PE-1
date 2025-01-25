#include "IntegralApproximation.h"
#include "LinearFunction.h"
#include "QuadraticFunction.h"
#include "StringFunction.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

void Approximate();

int main()
{
	Approximate();

	return 0;
}

void Approximate()
{
	IntegralApproximation approx = IntegralApproximation(-5, 5, new StringFunction("sin-5x * x + 5"));

	cout << fixed;
	cout << setprecision(15);

	cout << approx.IntegrateWithLeftRectangles(100000) << endl;
	cout << approx.IntegrateWithMidpointRectangles(100000) << endl;
	cout << approx.IntegrateWithRightRectangles(100000) << endl;
	cout << endl;
	cout << approx.IntegrateWithAllRectangles(100000) << endl;
	cout << endl;
	cout << approx.IntegrateWithTrapesoid(100000) << endl;
	cout << endl;
	cout << approx.IntegrateWithParabole(100000) << endl;
}