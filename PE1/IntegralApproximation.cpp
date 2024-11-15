#include "IntegralApproximation.h"

double IntegralApproximation::GetRange()
{
    return _b - _a;
}

double IntegralApproximation::IntegrateWithTrapesoid(unsigned int n)
{
    double height = GetRange() / n;
    double previousFunctionResult = _selectedFunction->ComputeWith(_a);
    double sum = 0;

    for (unsigned int i = 1; i <= n; i++) {
        double currentFunctionResult = _selectedFunction->ComputeWith(_a + height * i);
        sum += (previousFunctionResult + currentFunctionResult);
        previousFunctionResult = currentFunctionResult;
    }

    return sum * height * 0.5;
}