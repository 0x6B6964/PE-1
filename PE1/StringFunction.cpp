#include "StringFunction.h"
#include "CharUtil.h"

int StringFunction::ModifyString(string& str)
{
	for (int i = 0; i < str.length(); i++) {
		str[i] = CharUtil::ToLowerCase(str[i]);
		
		if (str[i] == ' ')
			str = str.substr(0, i) + str.substr(i + 1, str.length());
	}

	return 0;
}

float StringFunction::ComputeWith(float x)
{
	return _coreNode->Extract(x);
}

std::string StringFunction::ToString()
{
	return _stringFunction;
}
