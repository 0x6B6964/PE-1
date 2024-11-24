#include "BinomialNode.h"
#include "BinomialZeronaryOperationNode.h"
#include "BinomialXNode.h"
#include "BinomialUnaryOperatorNode.h"
#include "BinomialBinaryOperatorNode.h"

inline bool IsWordedConst(char ch);

BinomialNode* BinomialNode::CreateNode(StringParser& str, Subset set)
{
	int brackets = 0;

	// Binary + | -
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if ((str[i] == '+' || str[i] == '-') && brackets == 0)
		{
			if (i == set.GetStart()) // In case of unary + or - at the beginning
				continue;

			if (str.IsWordedFunctionFromEnd(i))
				continue;

			if (!CharUtil::IsOperation(str[i - 1])) {  // Only binary + an -
				return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i + 1, set.GetEnd() });
			}
		}
	}

	// * | /
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if ((str[i] == '*' || str[i] == '/') && brackets == 0)
		{
			return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i + 1, set.GetEnd() });
		}
	}

	// Worded functions
	if (CharUtil::IsLetter(str[set.GetStart()])) { // I only care if function is first thing in expression. Otherwise I want concat to execute
		int l = str.IsWordedFunction(set.GetStart());
		if (l) {
			return new BinomialUnaryOperatorNode(str, { set.GetStart(), set.GetStart() + l });
		}
	}

	// Concat
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
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
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str[i] == '(')
			brackets++;

		if (str[i] == ')')
			brackets--;

		if ((str[i] == '^') && brackets == 0)
		{
			return new BinomialBinaryOperatorNode(str, { set.GetStart(), i }, { i + 1, set.GetEnd() });
		}
	}

	// Unary + | -
	if (str[set.GetStart()] == '+' || str[set.GetStart()] == '-') { // At this point unary + and - should only be at the beggining of expression, so no need to investigate further
		return new BinomialUnaryOperatorNode(str, { set.GetStart(), set.GetEnd() });
	}

	// Worded consts (+ x)
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) { // I use loop here, to exclude all the non-existent letter expressions
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
	if (str[set.GetStart()] == '(') { // Except for brackets, but they are rigth here, so not to worry
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