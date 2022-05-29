/**
 * Driver file for the CS201's HW4 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "AlgebraicExpression.h"

int main() {
    std::cout << infix2prefix("( 12 + 5 ) - 20 * 4") << std::endl;
    std::cout << infix2postfix("( 5 + 7 ) * 3") << std::endl;
    std::cout << evaluateInfix("( 18 + 4 ) - 34 * 3") << std::endl;
    std::cout << prefix2infix("* - 254 / 9 4 - / 8 6 3") << std::endl;
    std::cout << prefix2postfix("* + 336 4 - 5 2") << std::endl;
    std::cout << evaluatePrefix("* + * 100 2 4 - 12 4") << std::endl;
    std::cout << postfix2infix("147 23 * 4 + 8 * 4 /") << std::endl;
    std::cout << postfix2prefix("644 25 5 - 7 * + 2 /") << std::endl;
    std::cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << std::endl;
}
