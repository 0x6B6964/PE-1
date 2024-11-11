#include "BinomialBinaryOperatorNode.h"
#include <Math.h>

float BinomialBinaryOperatorNode::Extract(const float& x)
{
    switch (_operationType) {
        case 0:
            return _operand1->Extract(x) + _operand2->Extract(x);
        case 1:
            return _operand1->Extract(x) - _operand2->Extract(x);
        case 2:
            return _operand1->Extract(x) * _operand2->Extract(x);
        case 3:
            return _operand1->Extract(x) / _operand2->Extract(x);
        case 4:
            return powf(_operand1->Extract(x), _operand2->Extract(x));
    }

    return 0.0f;
}
