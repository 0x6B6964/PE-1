#pragma once
#include "BinomialNode.h"

class BinomialZeronaryOperationNode : public BinomialNode
{
private: 
	float _numeral;

public:
	BinomialZeronaryOperationNode(StringParser& str, Subset set) : BinomialNode(str, set) {
		_numeral = str.ParseNumberAtPosition(set);
	}

	float Extract(const float& x) override;
};

