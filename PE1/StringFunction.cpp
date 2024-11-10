#include "StringFunction.h"
#include "CharUtil.h"
#include <math.h>
#define NO_EXCEPTION 0
#define INVALID_INPUT_EXCEPTION -1

string FindWord(const string& str, int& counter);
float ParseWord(const string str, const float x);
float ParseNumber(const string& str, int& counter);
int FindExpressionLength(const string& str, int startingIndex);

float StringFunction::ComputeWith(float x)
{
	return ParseFunctionAndYieldResult(_stringFunction, x);
}

string StringFunction::ToString()
{
	return _stringFunction;
}

int StringFunction::ToLowerCase(string& str)
{
	size_t length = str.length();

	for (int i = 0; i < length; i++)
		str[i] = CharUtil::ToLowerCase(str[i]);

	return NO_EXCEPTION;
}

float StringFunction::ParseFunctionAndYieldResult(string stringOfFunction, float x)
{
	size_t length = stringOfFunction.length();
	int startOfWord = -1;

	float sum = 0;
	float currentCache = 1;

	for (int i = 0; i < length; i++) {
		char currentChar = stringOfFunction[i];
		
		// Word parsing
		if (CharUtil::IsLetter(currentChar)) {
			currentCache *= ParseWord(FindWord(stringOfFunction, i), 
				ParseFunctionAndYieldResult(stringOfFunction.substr(i + 1, FindExpressionLength(stringOfFunction, i + 1)), x));
		}

		// Numbers parsing
		if (CharUtil::IsDigit(currentChar)) {
			currentCache *= ParseNumber(stringOfFunction, i);
		}

		// Operation Parsing
		if (currentChar == '+') {
			if (CharUtil::IsOperation(stringOfFunction[i - 1]) || stringOfFunction[i - 1] == '(') {
				// currentCache *= 1;
				continue;
			}

			sum += currentCache;
			currentCache = 1;
			continue;
		}

		if (currentChar == '-')
		{
			if (CharUtil::IsOperation(stringOfFunction[i - 1]) || stringOfFunction[i - 1] == '(') {
				currentCache *= -1;
				continue;
			}

			sum += currentCache;
			currentCache = -1;
			continue;
		}

		if (currentChar == '*') {
			continue;
		}

		if (currentChar == '/') {
			currentCache /= ParseFunctionAndYieldResult(stringOfFunction.substr(i + 1, FindExpressionLength(stringOfFunction, i + 1) - (i + 1)), x);
		}
		
		if (currentChar == '^') {
			currentCache = powf(currentCache, ParseFunctionAndYieldResult(stringOfFunction.substr(i + 1, FindExpressionLength(stringOfFunction, i + 1)), x));
		}
	}

	return sum;
}

string FindWord(const string& str, int& counter)
{
	if (!CharUtil::IsLetter(str[counter]))
		return "Invalid input";

	size_t length = str.length();
	int startOfTheWord = counter;

	for (counter; counter < length; counter++)
	{
		if (!CharUtil::IsLetter(str[counter]))
			break;
	}

	return str.substr(startOfTheWord, counter - startOfTheWord);
}

float ParseWord(string str, float x)
{
	if (str == "x")
		return x;
	if (str == "sqrt")
		return sqrtf(x);
	if (str == "sin")
		return sinf(x);
	if (str == "sec")
		return 1 / sinf(x);
	if (str == "cos")
		return cosf(x);
	if (str == "csc")
		return 1 / cosf(x);
	if (str == "tg")
		return tanf(x);
	if (str == "tan")
		return tanf(x);
	if (str == "ctg")
		return 1 / tanf(x);
	if (str == "pi")
		return (float)3.1415926;
	if (str == "lg")
		return log10f(x);
	if (str == "ln")
		return logf(x);

	return 1;
}

float ParseNumber(const string& str, int& counter)
{
	if (!CharUtil::IsDigit(str[counter]))
		return INVALID_INPUT_EXCEPTION;

	size_t length = str.length();
	int startOfNumber = counter;

	for (counter; counter < length; counter++) {
		if (!(CharUtil::IsDigit(str[counter]) || str[counter] == '.'))
			break;
	}

	return stof(str.substr(startOfNumber, --counter));
}

int FindExpressionLength(const string& str, const int startingIndex)
{
	int currentStart = startingIndex;

	while (str[currentStart] == '+' || str[currentStart] == '-')
		currentStart++;

	size_t length = str.length();

	if (currentStart > length)
		return INVALID_INPUT_EXCEPTION;

	bool verification = str[currentStart] != '*'
		&& str[currentStart] != '/'
		&& str[currentStart] != '^';

	if (!verification)
		return INVALID_INPUT_EXCEPTION;


	if (CharUtil::IsDigit(str[currentStart])) {
		ParseNumber(str, currentStart);
		currentStart++;
	}

	if (CharUtil::IsLetter(str[currentStart])) {
		FindWord(str, currentStart);
		return currentStart - startingIndex;
	}

	int bracketCount = 0;

	for (int i = currentStart; i < length; i++) {
		
		if (str[i] == '(')
			bracketCount++;
		if (str[i] == ')')
			bracketCount--;

		if (bracketCount == 0)
			return i - startingIndex;
	}

	return INVALID_INPUT_EXCEPTION;
}