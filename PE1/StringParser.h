#pragma once
#include <string>
#include "Subset.h"

using namespace std;

class StringParser
{
private:
	string _str;

	StringParser() { }

public:
	StringParser(string str) {
		_str = str;
	}

	char operator [](size_t idx) const { return _str[idx]; }

	inline string GetString() { return _str; }
	inline size_t length() { return _str.length(); }

#pragma region Expession boundaries

	static size_t FindEndOfExpression(const string& str, size_t startingCharacter = 0);
	inline size_t FindEndOfExpression(size_t startingCharacter = 0) { return FindEndOfExpression(_str, startingCharacter); }

	static inline string ExtractFullExpression(const string& str, size_t startingCharacter = 0) 
	{ return str.substr(startingCharacter, FindEndOfExpression(str, startingCharacter) - startingCharacter); }

#pragma endregion

#pragma region Word Parsing

	static Subset FindFirstWordPosition(const string& str, size_t startingCharacter = 0);
	inline Subset FindFirstWordPosition(size_t startingCharacter = 0) { return FindFirstWordPosition(_str, startingCharacter); }
	
	static inline string FindFirstWord(const string& str, size_t startingCharacter = 0) {
		Subset set = FindFirstWordPosition(str, startingCharacter);
		return str.substr(set.GetStart(), set.GetEnd() - set.GetStart());
	}
	inline string FindFirstWord(size_t startingCharacter = 0) { return FindFirstWord(_str, startingCharacter); }


	static int ParseWord(const string& str, Subset set);
	static inline int ParseWord(const string& str) { return ParseWord(str, Subset(0, str.length())); }
	inline int ParseWord(Subset set) { return ParseWord(_str, set); }

	static int IsWordedFunction(const string& str, size_t startingCharacter = 0); // returns length of the word
	inline int IsWordedFunction(size_t wordStart = 0) { return IsWordedFunction(_str, wordStart); }

#pragma endregion

#pragma region Number Parsing

	static Subset FindFirstNumberPosition(const string& str, size_t startingCharacter = 0);
	inline Subset FindFirstNumberPosition(size_t startingCharacter = 0) { return FindFirstNumberPosition(_str, startingCharacter); }
	
	static inline string FindFirstNumber(const string& str, size_t startingCharacter = 0)
	{
		Subset set = FindFirstNumberPosition(str, startingCharacter);
		return str.substr(set.GetStart(), set.GetEnd() - set.GetStart());
	}
	inline string FindFirstNumber(size_t startingCharacter= 0) { return FindFirstNumber(_str, startingCharacter); }

	static double ParseNumber(const string& str, Subset set);
	static inline double ParseNumber(const string& str) { return ParseNumber(str, Subset(0, str.length())); }
	inline double ParseNumberAtPosition(Subset set) { return ParseNumber(_str, set); }

#pragma endregion

};