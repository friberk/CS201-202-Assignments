/**
 * AlgebraicExpression implementation file for the CS201's HW4 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "AlgebraicExpression.h"

// Previous logic was causing an error in operator precedence
std::string infix2prefix(const std::string exp) {
    std::string postfixExp = infix2postfix(exp);
    return postfix2prefix(postfixExp);
}

std::string infix2postfix(const std::string exp) {
    Stack<std::string> s;
    std::string result = "";

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            result += tokens[i] + " ";
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            std::string c;
            s.getTop(c);
            while (!s.isEmpty() && (operatorPrecedence(c) >= operatorPrecedence(tokens[i]))) {
                std::string popped;
                s.pop(popped);
                result += popped + " ";
                s.getTop(c);
            }
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == '(') {
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == ')') {
            std::string c;
            s.getTop(c);
            while (!s.isEmpty() && c[0] != '(') {
                std::string popped;
                s.pop(popped);
                result += popped + " ";
                s.getTop(c);
            }
            s.pop();
        }
    }

    while (!s.isEmpty()) {
        std::string popped;
        s.pop(popped);
        result += popped + " ";
    }

    if (result.length() >= 1) {
        if (result[result.length() - 1] == ' ') {
            result.erase(result.length() - 1, 1);
        }
    }

    delete[] tokens;
    return result;
}

std::string prefix2infix(const std::string exp) {
    Stack<std::string> s;
    std::string result = "";

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = tokensSize - 1; i >= 0; i--) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            std::string s1 = "", s2 = "";
            s.pop(s1);
            s.pop(s2);
            s.push("( " + s1 + " " + tokens[i] + " " + s2 + " )");
        }
    }

    while (!s.isEmpty()) {
        std::string popped;
        s.pop(popped);
        result += popped + " ";
    }

    if (result.length() >= 1) {
        if (result[result.length() - 1] == ' ') {
            result.erase(result.length() - 1, 1);
        }
    }

    delete[] tokens;
    return result;
}

std::string prefix2postfix(const std::string exp) {
    Stack<std::string> s;
    std::string result = "";

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = tokensSize - 1; i >= 0; i--) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {

            std::string s1 = "", s2 = "";
            s.pop(s1);
            s.pop(s2);
            s.push(s1 + " " + s2 + " " + tokens[i]);
        }
    }

    while (!s.isEmpty()) {
        std::string popped;
        s.pop(popped);
        result += popped + " ";
    }

    if (result.length() >= 1) {
        if (result[result.length() - 1] == ' ') {
            result.erase(result.length() - 1, 1);
        }
    }

    delete[] tokens;
    return result;
}

std::string postfix2infix(const std::string exp) {
    Stack<std::string> s;
    std::string result = "";

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            std::string s1 = "", s2 = "";
            s.pop(s2);
            s.pop(s1);
            s.push("( " + s1 + " " + tokens[i] + " " + s2 + " )");
        }
    }
    while (!s.isEmpty()) {
        std::string popped;
        s.pop(popped);
        result += popped + " ";
    }

    if (result.length() >= 1) {
        if (result[result.length() - 1] == ' ') {
            result.erase(result.length() - 1, 1);
        }
    }

    delete[] tokens;
    return result;
}

std::string postfix2prefix(const std::string exp) {
    Stack<std::string> s;
    std::string result = "";

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(tokens[i]);
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            std::string s1 = "", s2 = "";
            s.pop(s2);
            s.pop(s1);
            s.push(tokens[i] + " " + s1 + " " + s2);
        }
    }

    while (!s.isEmpty()) {
        std::string popped;
        s.pop(popped);
        result += popped + " ";
    }

    if (result.length() >= 1) {
        if (result[result.length() - 1] == ' ') {
            result.erase(result.length() - 1, 1);
        }
    }

    delete[] tokens;
    return result;
}

double evaluateInfix(const std::string exp) {
    std::string postfixExp = infix2postfix(exp);
    return evaluatePostfix(postfixExp);
}

// Evalute the expression: <operator> <operand1> <operand2> = <another operand>
double evaluatePrefix(const std::string exp) {
    Stack<double> s;
    double result = 0;

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = tokensSize - 1; i >= 0; i--) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(std::atof(tokens[i].c_str()));
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            double s1 = 0, s2 = 0;
            s.pop(s1);
            s.pop(s2);
            s.push(evaluator(s1, s2, tokens[i][0]));
        }
    }

    double popped = 0;
    s.pop(popped);
    result += popped;

    delete[] tokens;
    return result;
}

// Evalute the expression: <operand1> <operand2> <operator> = <another operand>
double evaluatePostfix(const std::string exp) {
    Stack<double> s;
    double result = 0;

    int tokensSize = 0;
    std::string* tokens = tokenizer(exp, ' ', tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            s.push(std::atof(tokens[i].c_str()));
        }

        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' ||
                 tokens[i][0] == '/') {
            double s1 = 0, s2 = 0;
            s.pop(s2);
            s.pop(s1);
            s.push(evaluator(s1, s2, tokens[i][0]));
        }
    }

    double popped = 0;
    s.pop(popped);
    result += popped;

    delete[] tokens;
    return result;
}

int operatorPrecedence(const std::string operatorSymbol) {
    if (operatorSymbol[0] == '*' || operatorSymbol[0] == '/') {
        return 2;
    }

    else if (operatorSymbol[0] == '+' || operatorSymbol[0] == '-') {
        return 1;
    }

    else {
        return 0;
    }
}

std::string* tokenizer(const std::string& str, const char& delimiter, int& sizeOut) {
    int numOfTokens = 0;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            numOfTokens++;
        }
    }

    if (numOfTokens == 0) {
        bool isNumeric = true;

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                isNumeric = true;
            }

            else {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric == true) {
            sizeOut = 1;
            std::string* tokens = new std::string[1];
            tokens[0] = str;
            return tokens;
        }

        else {
            sizeOut = 0;
            return NULL;
        }
    }

    sizeOut = numOfTokens + 1;
    std::string* tokens = new std::string[numOfTokens + 1];
    int counter = 0;
    std::string token = "";

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == delimiter) {
            tokens[counter] = token;
            counter++;
            token = "";
        }

        else {
            token += str[i];
        }
    }
    tokens[counter] = token;

    return tokens;
}

double evaluator(double value1, double value2, char operation) {
    double returnVal;

    switch (operation) {
    case '+':
        returnVal = value1 + value2;
        break;
    case '-':
        returnVal = value1 - value2;
        break;
    case '*':
        returnVal = value1 * value2;
        break;
    case '/':
        (value2 == 0) ? returnVal = 0 : returnVal = value1 / value2;
        break;

    default:
        returnVal = 0;
        break;
    }

    return returnVal;
}
