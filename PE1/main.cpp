#include "IntegralApproximation.h"
#include "LinearFunction.h"
#include "QuadraticFunction.h"
#include "StringFunction.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	QuadraticFunction quad = QuadraticFunction(-1, 0, 10);
	StringFunction strf("sin(5x) * x + 5");
	IntegralApproximation approx = IntegralApproximation(-5, 5, &strf);

	cout << fixed;
	cout << setprecision(15);

	cout << endl << approx.IntegrateWithTrapesoid(100) << endl;
	cout << endl << approx.IntegrateWithTrapesoid(1000) << endl;
	cout << endl << approx.IntegrateWithTrapesoid(10000) << endl;
	cout << endl << approx.IntegrateWithTrapesoid(100000) << endl;
	cout << endl << approx.IntegrateWithTrapesoid(1000000) << endl;

	return 0;
}