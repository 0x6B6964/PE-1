#pragma once
#include "BinomialNode.h"
#define PI 3.141592653589793
#define E  2.718281828459045


class BinomialXNode : public BinomialNode
{
private:
	int _type; // 0 - x; 1 - pi; 2 - e; 3 - error, so 1

public:
	BinomialXNode(StringParser& str, Subset set) : BinomialNode()
	{
		switch (str[set.GetEnd() - 1]) {
			case 'x':
				_type = 0;
				break;
			case 'p':
				_type = 1;
				break;
			case 'e':
				_type = 2;
				break;
			default:
				_type = 0;
				break;
		}		
	}

	~BinomialXNode() { }

	double Extract(const double& x) override;
};

