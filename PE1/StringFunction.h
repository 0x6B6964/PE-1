#pragma once
#include "FunctionContainer.h"
#include <string>
#include "BinomialNode.h"

using namespace std;

class StringFunction : public FunctionContainer
{
private:
	string _stringFunction;
	BinomialNode* _coreNode;

	int ModifyString(string& str);

public:
	StringFunction(string selectedFunction) {
		_stringFunction = selectedFunction;

		ModifyString(selectedFunction);

		_coreNode = BinomialNode::CreateSource(StringParser(selectedFunction));
	}

	~StringFunction() {
		delete _coreNode;
	}

	double ComputeWith(double x) override;
	std::string ToString() override;
};