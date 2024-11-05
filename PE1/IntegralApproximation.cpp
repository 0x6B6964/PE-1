#include "IntegralApproximation.h"

float IntegralApproximation::GetRange()
{
    return _b - _a;
}

float IntegralApproximation::IntegrateWithTrapesoid(int n)
{
    float height = GetRange() / n;
    float previousFunctionResult = _selectedFunction->ComputeWith(_a);
    float sum = 0;

    for (int i = 1; i <= n; i++) {
        float currentFunctionResult = _selectedFunction->ComputeWith(_a + height * i);
        sum += (previousFunctionResult + currentFunctionResult);
        previousFunctionResult = currentFunctionResult;
    }

    return sum * height * 0.5;
}