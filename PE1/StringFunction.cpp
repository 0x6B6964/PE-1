#include "StringFunction.h"
#include "CharUtil.h"

float StringFunction::ComputeWith(float x)
{
	return _coreNode->Extract(x);
}

std::string StringFunction::ToString()
{
	return _stringFunction;
}

int StringFunction::ToLowerCase(string& str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = CharUtil::ToLowerCase(str[i]);

	return 0;
}
