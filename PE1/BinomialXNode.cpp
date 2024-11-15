#include "BinomialXNode.h"

double BinomialXNode::Extract(const double& x)
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
