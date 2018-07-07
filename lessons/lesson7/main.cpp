//
// Created by Petar Dzhambazov on 8.07.18.
//
#include <iostream>
#include "calc.h"
void executePointerFcn()
{
    int int1 = intInput("Enter first number: ");
    int int2 = intInput("Enter second number: ");
    char operation = opInput();

    arithmeticFcn pFunction = getArithmeticFunction(operation);
    if (pFunction)
    {
        std::cout << int1 << ' ' << operation << ' ' << int2 << " = " << pFunction(int1, int2);
    }
    else
    {
        std::cout << "Could not find appropriate arithmetic function\n";
    }
}
int main()
{
    executePointerFcn();
    return 0;
}