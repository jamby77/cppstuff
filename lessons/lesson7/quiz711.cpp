//
// Created by pdzhambazov on 09.07.18.
//
#include "quiz711.h"

int fac(const int n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    return fac(n - 1) * n;
}
