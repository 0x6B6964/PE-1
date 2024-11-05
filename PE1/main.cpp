#include "IntegralApproximation.h"
#include "LinearFunction.h"
#include "QuadraticFunction.h"
#include <iostream>
#include <iomanip>

int main()
{
	QuadraticFunction quad = QuadraticFunction(-1, 0, 10);
	IntegralApproximation approx = IntegralApproximation(-4, 4, &quad);

	std::cout << std::fixed;
	std::cout << std::setprecision(5);


	for (int i = 10; i <= 100; i += 10) {
		float result = approx.IntegrateWithTrapesoid(i);
		std::cout << i << ": " << result << " with difference " << 37.33333 - result << std::endl;
	}

	return 0;
}