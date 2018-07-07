//
// Created by Petar Dzhambazov on 8.07.18.
//

#ifndef IVA_CALC_H
#define IVA_CALC_H
int intInput(std::string prompt);
char opInput();
void clearCin();

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
//typedef int (*arithmeticFcn)(int, int);
using arithmeticFcn = int (*)(int, int);
arithmeticFcn getArithmeticFunction(char op);

struct arithmeticStruct
{
    char op;
    arithmeticFcn fcn;
};

static arithmeticStruct arithmeticArray[]{
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide},
};
#endif //IVA_CALC_H
