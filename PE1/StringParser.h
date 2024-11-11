#pragma once
#include <string>
#include "Subset.h"

using namespace std;

class StringParser
{
private:
	string _str;
	unsigned int _length;

	StringParser() { }

public:
	StringParser(string str) {
		_str = str;
		_length = str.length();
	}

	inline string GetString() { return _str; }
	inline unsigned int GetLength() { return _length; }

#pragma region Expession boundaries

	static unsigned int FindEndOfExpression(const string& str, unsigned int startingCharacter);
	static inline unsigned int FindEndOfExpression(const string& str) { return FindEndOfExpression(str, 0); }
	
	inline unsigned int FindEndOfExpression(unsigned int startingCharacter) { return FindEndOfExpression(_str, startingCharacter); }
	inline unsigned int FindEndOfExpression() { return FindEndOfExpression(0); }

	static inline string ExtractFullExpression(const string& str, unsigned int startingCharacter) { return str.substr(startingCharacter, FindEndOfExpression(str, startingCharacter) - startingCharacter); }
	static inline string ExtractFullExpression(const string& str) { return ExtractFullExpression(str, 0); }

#pragma endregion

#pragma region Word Parsing

	static Subset FindFirstWordPosition(const string& str, unsigned int startingCharacter);
	static inline Subset FindFirstWordPosition(const string& str) { return FindFirstWordPosition(str, 0); }

	inline Subset FindFirstWordPosition(unsigned int startingCharacter) { return FindFirstWordPosition(_str, startingCharacter); }
	inline Subset FindFirstWordPosition() { return FindFirstWordPosition(0); }
	
	static inline string FindFirstWord(const string& str, unsigned int startingCharacter) {
		Subset set = FindFirstWordPosition(str, startingCharacter);
		return str.substr(set.GetStart(), set.GetEnd() - set.GetStart());
	}
	static inline string FindFirstWord(const string& str) { return FindFirstWord(str, 0); }
	
	inline string FindFirstWord(unsigned int startingCharacter) { return FindFirstWord(_str, 0); }
	inline string FindFirstWord() { return FindFirstWord(0); }


	static int ParseWord(const string& str, Subset set);
	static inline int ParseWord(const string& str) { return ParseWord(str, Subset(0, str.length())); }
	inline int ParseWord(Subset set) { return ParseWord(_str, set); }

	static int IsWordedFunction(const string& str, unsigned int startingCharacter); // returns length of the word
	static inline int IsWordedFunction(const string& str) { return IsWordedFunction(str, 0); }
	inline int IsWordedFunction(unsigned int wordStart) { return IsWordedFunction(_str, wordStart); }

#pragma endregion

#pragma region Number Parsing

	static Subset FindFirstNumberPosition(const string& str, unsigned int startingCharacter);
	static inline Subset FindFirstNumberPosition(const string& str) { return FindFirstNumberPosition(str, 0); }
	
	inline Subset FindFirstNumberPosition(unsigned int startingCharacter) { return FindFirstNumberPosition(_str, startingCharacter); }
	inline Subset FindFirstNumberPosition() { return FindFirstNumberPosition(0); }
	
	static inline string FindFirstNumber(const string& str, int startingCharacter) 
	{
		Subset set = FindFirstNumberPosition(str, startingCharacter);
		return str.substr(set.GetStart(), set.GetEnd() - set.GetStart());
	}
	static inline string FindFirstNumber(const string& str) { return FindFirstNumber(str, 0); }
	
	inline string FindFirstNumber(int startingCharacter) { return FindFirstNumber(_str, startingCharacter); }
	inline string FindFirstNumber() { return FindFirstNumber(0); }

	static float ParseNumber(const string& str, Subset set);
	static inline float ParseNumber(const string& str) { return ParseNumber(str, Subset(0, str.length())); }
	inline float ParseNumberAtPosition(Subset set) { return ParseNumber(_str, set); }

#pragma endregion

};