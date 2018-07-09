//
// Created by Petar Dzhambazov on 8.07.18.
//
#include <iostream>
#include "calc.h"
#include "quiz711.h"

void executePointerFcn() {
    int int1 = intInput("Enter first number: ");
    int int2 = intInput("Enter second number: ");
    char operation = opInput();

    arithmeticFcn pFunction = getArithmeticFunction(operation);
    if (pFunction) {
        std::cout << int1 << ' ' << operation << ' ' << int2 << " = " << pFunction(int1, int2);
    } else {
        std::cout << "Could not find appropriate arithmetic function\n";
    }
}

void testFac() {
    int n[]{0, 1, 2, 3, 4, 5, 6, 7};
    for (auto i : n) {
        std::cout << fac(i) << '\n';
    }
}

int main() {
//    executePointerFcn();
    testFac();
    return 0;
}
