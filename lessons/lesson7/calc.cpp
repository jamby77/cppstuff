//
// Created by Petar Dzhambazov on 8.07.18.
//

#include <iostream>
#include "calc.h"
const char operators[]{'+', '-', '*', '/'};
bool isValidOperator(char op);
int intInput(std::string prompt)
{
    int i;
    do
    {
        clearCin();
        std::cout << prompt;
        std::cin >> i;
    }
    while (std::cin.fail());
    return i;
}
void clearCin()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}
char opInput()
{
    clearCin();
    char op;
    do
    {
        std::cout << "Enter operator (‘+’, ‘-‘, ‘*’, ‘/’): ";
        std::cin >> op;
    }
    while (!isValidOperator(op));
    return op;
}
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a*b;
}
int divide(int a, int b)
{
    if (b!=0)
    {
        return a/b;
    }
    return 0;
}
arithmeticFcn getArithmeticFunction(const char op)
{
    for (const auto &item : arithmeticArray)
    {
        if (item.op == op) {
            return item.fcn;
        }
    }
    return nullptr;
}
bool isValidOperator(const char op)
{
    for (auto validOp : operators)
    {
        if (op==validOp)
        {
            return true;
        }
    }
    return false;
}

