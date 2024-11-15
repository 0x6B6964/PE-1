#pragma once
#include "BinomialNode.h"

class BinomialZeronaryOperationNode : public BinomialNode
{
private: 
	double _numeral;

public:
	BinomialZeronaryOperationNode(StringParser& str, Subset set) : BinomialNode(str, set) {
		_numeral = str.ParseNumberAtPosition(set);
	}

	double Extract(const double& x) override;
};

