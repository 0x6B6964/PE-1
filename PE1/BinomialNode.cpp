#include "BinomialNode.h"
#include "BinomialZeronaryOperationNode.h"
#include "BinomialXNode.h"
#include "BinomialUnaryOperatorNode.h"
#include "BinomialBinaryOperatorNode.h"

BinomialNode* BinomialNode::CreateNode(StringParser& str, Subset set)
{
	int brackets = 0;

	// Binary + | -
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str.GetString()[i] == '(')
			brackets++;

		if (str.GetString()[i] == ')')
			brackets--;


		if ((str.GetString()[i] == '+' || str.GetString()[i] == '-') && brackets == 0)
		{
			if (i == 0) // In case of unary + or - at the beginning
				continue;

			if (!CharUtil::IsOperation(str.GetString()[i - 1])) {  // Only binary + an -
				BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i + 1, set.GetEnd()});
				return &op;
			}
		}
	}

	// * | /
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str.GetString()[i] == '(')
			brackets++;

		if (str.GetString()[i] == ')')
			brackets--;

		if ((str.GetString()[i] == '*' || str.GetString()[i] == '/') && brackets == 0)
		{
			BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i + 1, set.GetEnd() });
			return &op;
		}
	}

	// ^
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) {
		if (str.GetString()[i] == '(')
			brackets++;

		if (str.GetString()[i] == ')')
			brackets--;

		if ((str.GetString()[i] == '^') && brackets == 0)
		{
			BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i + 1, set.GetEnd() });
			return &op;
		}
	}

	// Worded functions
	if (CharUtil::IsLetter(str.GetString()[set.GetStart()])) { // I only care if function is first thing in expression. Otherwise I want concat to execute
		int l = str.IsWordedFunction(set.GetStart());
		if (l) {
			BinomialUnaryOperatorNode op(str, { set.GetStart(), str.FindEndOfExpression(set.GetStart() + l) });
			return &op;
		}
	}

	// Concat
	for (unsigned int i = set.GetStart() + 1; i < set.GetEnd(); i++) {
		if (str.GetString()[i] == '(')
			brackets++;

		if (str.GetString()[i] == ')')
			brackets--;

		if (CharUtil::IsDigit(str.GetString()[i - 1]) && CharUtil::IsLetter(str.GetString()[i]) && brackets == 0) { // 3x
			BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i, set.GetEnd() });
			return &op;
		}

		if ((CharUtil::IsDigit(str.GetString()[i - 1]) || CharUtil::IsLetter(str.GetString()[i - 1])) && str.GetString()[i] == '(' && brackets == 1) { // 3(x+2) || x(x+2)
			BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i, set.GetEnd() });
			return &op;
		}

		if (CharUtil::IsLetter(str.GetString()[i]) && str.GetString()[i - 1] == ')' && brackets == 0) { // (x + 2)x
			BinomialBinaryOperatorNode op(str, { set.GetStart(), i }, { i, set.GetEnd() });
			return &op;
		}
	}

	// Unary + | -
	if (str.GetString()[set.GetStart()] == '+' || str.GetString()[set.GetStart()] == '-') { // At this point unary + and - should only be at the beggining of expression, so no need to investigate further
		BinomialUnaryOperatorNode op(str, { set.GetStart(), set.GetEnd() });
		return &op;
	}

	// Worded consts (+ x)
	for (unsigned int i = set.GetStart(); i < set.GetEnd(); i++) { // I use loop here, to exclude all the non-existent letter expressions
		if (str.GetString()[i] == '(')
			brackets++;

		if (str.GetString()[i] == ')')
			brackets--;

		if ((str.GetString()[i] == 'x' || str.GetString()[i] == 'p' || str.GetString()[i] == 'e') && brackets == 0) {
			BinomialXNode op(str, { set.GetStart(), i + 1 });
			return &op;
		}
	}

	// Insertion of literals
	if (CharUtil::IsDigit(str.GetString()[set.GetStart()])) { // At this point we should be left with just float values, so...
		BinomialZeronaryOperationNode op(str, set);
		return &op;
	}

	// Extracting the brackets
	if (str.GetString()[set.GetStart()]) { // Except for brackets, but they are rigth here, so not to worry
		BinomialUnaryOperatorNode op(str, { 0, 0 });
		return &op;
	}

	BinomialZeronaryOperationNode op(str, { 1, 1 });
	return &op;
}

float BinomialNode::Extract(const float& x)
{
	return 1.0f;
}
;