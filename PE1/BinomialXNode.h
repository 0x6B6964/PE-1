#pragma once
#include "BinomialNode.h"
#define PI 3.14159265359
#define E  2.71828182846


class BinomialXNode : public BinomialNode
{
private:
	int _type; // 0 - x; 1 - pi; 2 - e; 3 - error, so 1

public:
	BinomialXNode(StringParser& str, Subset set) : BinomialNode(str, { 0, 0 })
	{
		switch (str.GetString()[set.GetEnd() - 1]) {
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

	float Extract(const float& x) override;
};

