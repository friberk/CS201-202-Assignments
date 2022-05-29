/**
 * AlgebraicExpression header file for the CS201's HW4 assignment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __ALGEBRAICEXPRESSION_H__
#define __ALGEBRAICEXPRESSION_H__

#include "Stack.h"
#include <cstdlib>
#include <string>

// It converts an infix expression exp to its equivalent prefix form.
std::string infix2prefix(const std::string exp);

// It converts an infix expression exp to its equivalent postfix form.
std::string infix2postfix(const std::string exp);

// It converts a prefix expression exp to its equivalent infix form.
std::string prefix2infix(const std::string exp);

// It converts a prefix expression exp to its equivalent postfix form.
std::string prefix2postfix(const std::string exp);

// It converts a postfix expression exp to equivalent infix form.
std::string postfix2infix(const std::string exp);

// It converts a postfix expression exp to equivalent prefix form.
std::string postfix2prefix(const std::string exp);

// It evaluates an infix expression.
double evaluateInfix(const std::string exp);

// It evaluates a prefix expression.
double evaluatePrefix(const std::string exp);

// It evaluates a postfix expression.
double evaluatePostfix(const std::string exp);

int operatorPrecedence(const std::string operatorSymbol);

std::string* tokenizer(const std::string& str, const char& delimiter, int& sizeOut);

double evaluator(double value1, double value2, char operation);

#endif // __ALGEBRAICEXPRESSION_H__
