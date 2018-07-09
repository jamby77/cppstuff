//
// Created by pdzhambazov on 09.07.18.
//
#include <iostream>
#include "quiz711.h"

int fac(const int n) {
    if (n <= 0) {
        return 1;
    }

    return fac(n - 1) * n;
}

int digitSum(int n) {
    if (n < 10) {
        return n;
    }

    return digitSum(n / 10) + n % 10;
}

void printDecToBin(unsigned int n) {
    if (n > 1) {
        printDecToBin(n / 2);
    }
    std::cout << n % 2;
}

