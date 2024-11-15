#include "BinomialUnaryOperatorNode.h"
#include <Math.h>

double BinomialUnaryOperatorNode::Extract(const double& x)
{
	switch (_operationType) {
		case -1:
			return -_operand->Extract(x);
		case 1:
			return sqrt(_operand->Extract(x));
		case 2:
			return sin(_operand->Extract(x));
		case 3:
			return 1 / sin(_operand->Extract(x));
		case 4:
			return cos(_operand->Extract(x));
		case 5:
			return 1 / cos(_operand->Extract(x));
		case 6:
			return tan(_operand->Extract(x));
		case 7:
			return 1 / tan(_operand->Extract(x));
		case 8:
			return log10(_operand->Extract(x));
		case 9:
			return log(_operand->Extract(x));
	}

	return _operand->Extract(x);
}
