#include "BinomialNode.h"
#include "BinomialZeronaryOperationNode.h"
#include "BinomialXNode.h"
#include "BinomialUnaryOperatorNode.h"
#include "BinomialBinaryOperatorNode.h"

inline bool IsWordedConst(char ch);
bool ContainsAnyOfSymbols(StringParser& str, Subset set, char* chArray, int characterNumber, size_t& outPosition);

BinomialNode* BinomialNode::CreateNode(StringParser& str, Subset set)
{
	size_t position = set.GetStart(); 
	
	// Binary + | -
	char binaryAdditionSymbols[2] = {'+', '-'};
	if(ContainsAnyOfSymbols(str, set, binaryAdditionSymbols, 2, position))
		return new BinomialBinaryOperatorNode(str, { set.GetStart(), position }, { position + 1, set.GetEnd() });

	// * | /
	char multiplicationSymbols[2] = {'*', '/'};
	if(ContainsAnyOfSymbols(str, set, multiplicationSymbols, 2, position))
		return new BinomialBinaryOperatorNode(str, { set.GetStart(), position }, { position + 1, set.GetEnd() });

	// Worded functions
	if (CharUtil::IsLetter(str[set.GetStart()])) { // I only care if function is first thing in expression. Otherwise I want concat to execute
		int l = str.IsWordedFunction(set.GetStart());
		if (l)
			return new BinomialUnaryOperatorNode(str, { set.GetStart(), set.GetStart() + l });
	}

	int brackets = 0;

	// Concat
	for (size_t i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if (i == set.GetStart())
			continue;

		if (CharUtil::IsDigit(str[i - 1]) && CharUtil::IsLetter(str[i]) && brackets == 0) { // 3x
			return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i, set.GetEnd() });
		}

		if ((CharUtil::IsDigit(str[i - 1]) || CharUtil::IsLetter(str[i - 1])) && str[i] == '(' && brackets == 1) { // 3(x+2) || x(x+2)
			return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i, set.GetEnd() });
		}

		if (CharUtil::IsLetter(str[i]) && str[i - 1] == ')' && brackets == 0) { // (x + 2)x
			return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i, set.GetEnd() });
		}
	}

	// ^
	char exponansiationSymbols[1] = {'^'};
	if(ContainsAnyOfSymbols(str, set, exponansiationSymbols, 1, position))
		return new BinomialBinaryOperatorNode(str, { set.GetStart(), position }, { position + 1, set.GetEnd() });


	// Unary + | -
	if (str[set.GetStart()] == '+' || str[set.GetStart()] == '-') { // At this point unary + and - should only be at the begining of expression, so no need to investigate further
		return new BinomialUnaryOperatorNode(str, { set.GetStart(), set.GetEnd() });
	}

	// Worded consts (+ x)	
	for (size_t i = set.GetStart(); i < set.GetEnd(); i++) { // I use loop here, to exclude all the non-existent letter expressions
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if (IsWordedConst(str[i]) && brackets == 0) {
			return new BinomialXNode(str, { set.GetStart(), i + 1 });
		}
	}

	// Insertion of literals
	if (CharUtil::IsDigit(str[set.GetStart()])) { // At this point we should be left with just numerical values, so...
		return new BinomialZeronaryOperationNode(str, set);
	}

	// Extracting the brackets
	if (str[set.GetStart()] == '(') { // Except for brackets, but they are right here, so not to worry
		return new BinomialUnaryOperatorNode(str, { set.GetStart(), str.FindEndOfExpression(set.GetStart()) });
	}

	return new BinomialZeronaryOperationNode();
}

double BinomialNode::Extract(const double& x)
{
	return 1.0f;
};

inline bool IsWordedConst(char ch) {
	return ch == 'x' || ch == 'p' || ch == 'e';
}

/// <summary>
/// Only use for operations
/// </summary>
bool ContainsAnyOfSymbols(StringParser& str, Subset set, char* chArray, int characterNumber, size_t& outPosition) {
	int brackets = 0;

	for (size_t i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if (brackets != 0)
			continue;

		for(int j = 0; j < characterNumber; j++) {			
			if(str[i] == chArray[j])
			{
				if (i == set.GetStart()) // Guard clauses for unary operations
					continue;

				if (str.IsWordedFunctionFromEnd(i))
					continue;

				if (CharUtil::IsOperation(str[i - 1]))
					continue;

				outPosition = i;
				return true;
			}
		}
	}

	return false;
}