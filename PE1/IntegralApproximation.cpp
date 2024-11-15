#include "IntegralApproximation.h"

double IntegralApproximation::GetRange()
{
    return _b - _a;
}

double IntegralApproximation::IntegrateWithLeftRectangles(unsigned int n)
{
    double height = GetRange() / n;
    double sum = 0;

    for (unsigned int i = 0; i < n; i++) {
        sum += _selectedFunction->ComputeWith(_a + height * i);
    }

    return sum * height;
}

double IntegralApproximation::IntegrateWithMidpointRectangles(unsigned int n)
{
    double height = GetRange() / n;
    double previousFunctionResult = _selectedFunction->ComputeWith(_a);
    double sum = 0;

    for (double i = 0.5; i < n; i++) {
        sum += _selectedFunction->ComputeWith(_a + height * i);
    }

    return sum * height;
}

double IntegralApproximation::IntegrateWithRightRectangles(unsigned int n)
{
    double height = GetRange() / n;
    double sum = 0;

    for (unsigned int i = 1; i <= n; i++) {
        sum += _selectedFunction->ComputeWith(_a + height * i);
    }

    return sum * height;
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

double IntegralApproximation::IntegrateWithParabole(unsigned int n)
{
    double height = (_b - _a) / n;
    double sum = -0.5 * _selectedFunction->ComputeWith(_a);

    for (unsigned int i = 0; i < n; i++)
    {
        sum += _selectedFunction->ComputeWith(_a + height * i) + 2 * _selectedFunction->ComputeWith(_a + height * (i + 0.5));
    }

    sum += 0.5 * _selectedFunction->ComputeWith(_b);
    sum *= height / 3;

    return sum;
}
