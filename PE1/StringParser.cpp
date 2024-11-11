#include "StringParser.h"
#include "CharUtil.h"

unsigned int StringParser::FindEndOfExpression(const string& str, unsigned int startingCharacter) 
{
	for (int i = startingCharacter; i < str.length(); i++) {
		if (CharUtil::IsOperation(str[i]) && str[i] != '^')
			return i - 1;
	}
	
	return str.length() - 1;
}

Subset StringParser::FindFirstWordPosition(const string& str, unsigned int startingCharacter)
{
	size_t length = str.length();
	int startOfTheWord = startingCharacter;

	for (startOfTheWord; startingCharacter < length; startOfTheWord++) {
		if (CharUtil::IsLetter(str[startOfTheWord]))
			break;
	}

	int endOfTheWord = startOfTheWord;

	for (endOfTheWord; endOfTheWord < endOfTheWord; endOfTheWord++)
	{
		if (!CharUtil::IsLetter(str[endOfTheWord]))
			break;
	}

	return Subset(startOfTheWord, endOfTheWord - 1);
}

int StringParser::ParseWord(const string& str, Subset set)
{
	if (str == "sqrt")
		return 1;
	if (str == "sin")
		return 2;
	if (str == "sec")
		return 3;
	if (str == "cos")
		return 4;
	if (str == "csc")
		return 5;
	if (str == "tg")
		return 6;
	if (str == "tan")
		return 7;
	if (str == "ctg")
		return 7;
	if (str == "lg")
		return 8;
	if (str == "ln")
		return 9;

	return 0;
}

int StringParser::IsWordedFunction(const string& str, unsigned int startingCharacter)
{
	for (unsigned int i = startingCharacter; i < str.length(); i++)
	{
		string substring = str.substr(startingCharacter, i - startingCharacter);
		
		if (ParseWord(substring))
			return i - startingCharacter;
	}

	return 0;
}

Subset StringParser::FindFirstNumberPosition(const string& str, unsigned int startingCharacter)
{
	size_t length = str.length();

	int startOfNumber = startingCharacter;

	for (startOfNumber; startOfNumber < length; startOfNumber++) {
		if ((CharUtil::IsDigit(str[startOfNumber])))
			break;
	}

	int endOfNumber = startOfNumber;
	int numberOfPoints = 0;

	for (endOfNumber; endOfNumber < length; endOfNumber++) {
		if (str[endOfNumber] == '.')
			numberOfPoints++;
		if (!(CharUtil::IsDigit(str[endOfNumber]) || numberOfPoints < 2))
			break;
	}

	return Subset(startOfNumber, endOfNumber - 1);
}

float StringParser::ParseNumber(const string& str, Subset set)
{
	return stof(str.substr(set.GetStart(), set.GetEnd() - set.GetStart()));
}
