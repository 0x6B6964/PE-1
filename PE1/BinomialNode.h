#pragma once
#include <string>
#include "CharUtil.h"
#include "StringParser.h"

using namespace std;

class BinomialNode
{
protected:
	static BinomialNode* CreateNode(StringParser& str, Subset set);

public:
	BinomialNode(StringParser& str, Subset set)
	{
		
	}
	virtual float Extract(const float& x);

	static inline BinomialNode* CreateSource(StringParser str) { return CreateNode(str, { 0, str.GetLength() }); }
};