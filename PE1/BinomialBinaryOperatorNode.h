#pragma once
#include "BinomialNode.h"

class BinomialBinaryOperatorNode : public BinomialNode
{
	int _operationType;
	BinomialNode* _operand1;
	BinomialNode* _operand2;

public: 
	BinomialBinaryOperatorNode(StringParser& str, Subset set1, Subset set2) : BinomialNode() {
		_operand1 = CreateNode(str, set1);
		_operand2 = CreateNode(str, set2);

		switch (str[set1.GetEnd()]) {
			case '+':
				_operationType = 0;
				break;
			case '-':
				_operationType = 1;
				break;
			case '*':
				_operationType = 2;
				break;
			case '/':
				_operationType = 3;
				break;
			case '^':
				_operationType = 4;
				break;
			default:
				_operationType = 2;
				break;
		}
	}

	~BinomialBinaryOperatorNode() {
		delete _operand1;
		delete _operand2;
	}

	double Extract(const double& x) override;
};

