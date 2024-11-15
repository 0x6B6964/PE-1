#pragma once
#include "BinomialNode.h"

class BinomialUnaryOperatorNode : public BinomialNode
{
private:
	int _operationType; // -1 - unary -, 0 - unary +,
	BinomialNode* _operand;

public:
	BinomialUnaryOperatorNode(StringParser& str, Subset set) : BinomialNode(str, set)
	{
		Subset operandSet;

		_operationType = 0;

		if (str.GetString()[set.GetStart()] == '-') {
			_operationType = -1;
			operandSet = { set.GetStart() + 1, set.GetEnd() };
		} else if (str.GetString()[set.GetStart()] == '+') {
			_operationType = 0;
			operandSet = { set.GetStart() + 1, set.GetEnd() };
		} else if (str.IsWordedFunction(set.GetStart())) {
			_operationType = str.ParseWord(set);
			operandSet = { set.GetEnd(), str.FindEndOfExpression(set.GetEnd()) };
		} else if (str.GetString()[set.GetStart()] == '(') {
			_operationType = 0;
			operandSet = { set.GetStart() + 1, set.GetEnd() - 1 };
		}
		
		_operand = CreateNode(str, operandSet);
	}

	float Extract(const float& x) override;
};