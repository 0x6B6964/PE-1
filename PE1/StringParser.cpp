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

		if (CharUtil::IsOperation(str[i - 1]) || i != startingCharacter)
			continue;

		return i - 1;
	}
	
	return str.length() - 1;
}

Subset StringParser::FindFirstWordPosition(const string& str, size_t startingCharacter)
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
	string sub = str.substr(set.GetStart(), set.GetEnd() - set.GetStart());

	if (sub == "sqrt")
		return 1;
	if (sub == "sin")
		return 2;
	if (sub == "sec")
		return 3;
	if (sub == "cos")
		return 4;
	if (sub == "csc")
		return 5;
	if (sub == "tg")
		return 6;
	if (sub == "tan")
		return 7;
	if (sub == "ctg")
		return 7;
	if (sub == "lg")
		return 8;
	if (sub == "ln")
		return 9;

	return 0;
}

int StringParser::IsWordedFunction(const string& str, size_t startingCharacter)
{
	for (unsigned int i = startingCharacter; i < str.length(); i++)
	{
		string substring = str.substr(startingCharacter, i - startingCharacter);
		
		if (ParseWord(substring))
			return i - startingCharacter;
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
