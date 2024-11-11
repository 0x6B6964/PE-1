#include "BinomialUnaryOperatorNode.h"
#include <Math.h>

float BinomialUnaryOperatorNode::Extract(const float& x)
{
	switch (_operationType) {
		case -1:
			return -_operand->Extract(x);
		case 1:
			return sqrtf(_operand->Extract(x));
		case 2:
			return sinf(_operand->Extract(x));
		case 3:
			return 1 / sinf(_operand->Extract(x));
		case 4:
			return cosf(_operand->Extract(x));
		case 5:
			return 1 / cosf(_operand->Extract(x));
		case 6:
			return tanf(_operand->Extract(x));
		case 7:
			return 1 / tanf(_operand->Extract(x));
		case 8:
			return log10(_operand->Extract(x));
		case 9:
			return log(_operand->Extract(x));
	}

	return _operand->Extract(x);
}
