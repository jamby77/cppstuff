//
// Created by pdzhambazov on 04.07.18.
//

#include <iostream>
#include "dyn-array.h"

int main() {
    int l = requestNamesLength();
    std::string *names = requestNames(l);

    sortNames(names, l);
    printNames(names, l);
    return 0;
}

