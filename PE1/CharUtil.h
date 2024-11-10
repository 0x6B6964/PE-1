#pragma once
class CharUtil
{
private: 
	CharUtil() { }

public:
	static inline bool IsLetter(char ch) { return IsUpperCase(ch) || IsLowerCase(ch); }
	static inline bool IsUpperCase(char ch) { return ch > 0x40 && ch < 0x5B; /* ch is A - Z */ }
	static inline bool IsLowerCase(char ch) { return ch > 0x60 && ch < 0x7B; /* ch is a - z */ }
	static inline bool IsDigit(char ch) { return ch > 0x2F && ch < 0x3A; /* ch is 0 - 9 */ }
	static inline bool IsOperation(char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'; }

	static inline char ToUpperCase(char ch)	{
		if (IsLowerCase(ch))
			return ch + 0x20;
		return ch;
	}
	static inline char ToLowerCase(char ch) {
		if (IsUpperCase(ch))
			return ch - 0x20;
		return ch;
	}
	static inline int DigitToInt(char ch) {
		if (IsDigit(ch))
			return ch - 0x30;
		return ch;
	}
};

