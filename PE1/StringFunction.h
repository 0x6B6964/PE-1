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

public:
	StringFunction(string selectedFunction) {
		_stringFunction = selectedFunction;

		ToLowerCase(selectedFunction);

		_coreNode = BinomialNode::CreateSource(StringParser(selectedFunction));
	}

	float ComputeWith(float x) override;
	std::string ToString() override;

	/// <summary>
	/// Changes every letter in string to lowercase (by reference)
	/// </summary>
	static int ToLowerCase(string& str);
};