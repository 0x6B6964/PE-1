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

	~BinomialZeronaryOperationNode() { }

	double Extract(const double& x) override;
};

