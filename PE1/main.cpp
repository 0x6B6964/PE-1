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
	StringFunction strf("sinx");
	IntegralApproximation approx = IntegralApproximation(0, 5, &strf);

	std::cout << fixed;
	std::cout << setprecision(5);

	std::cout << endl << approx.IntegrateWithTrapesoid(100) << endl;

	return 0;
}