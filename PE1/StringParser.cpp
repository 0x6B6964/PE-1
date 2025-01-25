#include "StringParser.h"
#include "CharUtil.h"

size_t StringParser::FindEndOfExpression(const string& str, size_t startingCharacter)
{
	int brackets = 0;

	for (size_t i = startingCharacter; i < str.length(); i++) {
		if (str[i] == '(')
			brackets++;
		
		if (str[i] == ')')
			brackets--;
		
		
		if (str[i] == ')') {
			if (brackets == 0)
				return i + 1;

			if (brackets < 0)
				return i;
		}
			

		if (brackets > 0)
			continue;

		if (!(CharUtil::IsOperation(str[i]) && str[i] != '^'))
			continue;

		if (CharUtil::IsOperation(str[i - 1]) || i == startingCharacter)
			continue;

		return i;
	}
	
	return str.length() - 1;
}

Subset StringParser::FindFirstWordPosition(const string& str, size_t startingCharacter)
{
	size_t length = str.length();
	size_t startOfTheWord = startingCharacter;

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

int StringParser::ParseWord(const string& str)
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
		return 6;
	if (str == "ctg")
		return 7;
	if (str == "lg")
		return 8;
	if (str == "ln")
		return 9;

	return 0;
}

int StringParser::IsWordedFunction(const string& str, size_t startingCharacter)
{
	unsigned int endingCharacter = startingCharacter + 4 < str.length() ? startingCharacter + 4 : str.length(); // Clamp // 4 being legth of longest worded function

	for (unsigned int i = startingCharacter; i < endingCharacter; i++)
	{
		string substring = str.substr(startingCharacter, i - startingCharacter);
		
		if (ParseWord(substring))
			return i - startingCharacter;
	}

	return 0;
}

int StringParser::IsWordedFunctionFromEnd(const string& str, size_t endingCharacter)
{
	unsigned int startingCharacter = endingCharacter > 4 ? endingCharacter - 4 : 0; // Clamp // 4 being legth of longest worded function

	for (unsigned int i = startingCharacter; i < endingCharacter; i++) 
	{
		string substring = str.substr(i, endingCharacter - i);

		if (ParseWord(substring))
			return endingCharacter - i;
	}

	return 0;
}

Subset StringParser::FindFirstNumberPosition(const string& str, size_t startingCharacter)
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

double StringParser::ParseNumber(const string& str, Subset set)
{
	return stof(str.substr(set.GetStart(), set.GetEnd() - set.GetStart()));
}
