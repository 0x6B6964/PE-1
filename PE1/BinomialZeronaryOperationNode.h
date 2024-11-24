#pragma once
#include "BinomialNode.h"

class BinomialZeronaryOperationNode : public BinomialNode
{
private: 
	double _numeral;

public:
	BinomialZeronaryOperationNode() {
		_numeral = 0;
	}

	BinomialZeronaryOperationNode(StringParser& str, Subset set) : BinomialNode() {
		_numeral = str.ParseNumberAtPosition(set);
	}

	~BinomialZeronaryOperationNode() { }

	double Extract(const double& x) override;
};

