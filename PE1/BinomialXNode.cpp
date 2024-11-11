#include "BinomialXNode.h"

float BinomialXNode::Extract(const float& x)
{
	switch (_type) {
		case 0:
			return x;
		case 1:
			return PI;
		case 2:
			return E;
	}

    return 1;
}
