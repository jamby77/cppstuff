//
// Created by pdzhambazov on 04.07.18.
//

#include <iostream>
#include <string>
#include "dyn-array.h"


int requestNamesLength() {
    std::cout << "How many names would you like to enter? ";
    int namesLength;
    std::cin >> namesLength;
    std::cin.ignore(32767, '\n');
    return namesLength;
}

std::string *requestNames(int namesLength) {
    auto *names = new std::string[namesLength];
    for (int i = 0; i < namesLength; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";

        std::cin >> names[i];
    }

    return names;
}

void sortNames(std::string *names, int length) {
    for (int startIdx = 0; startIdx < length - 1; ++startIdx) {
        int smIdx = startIdx;
        for (int j = startIdx; j < length; ++j) {
            if (names[j] < names[smIdx]) {
                smIdx = j;
            }
        }
        std::swap(names[startIdx], names[smIdx]);
    }
}

void printNames(std::string *names, int length) {
    std::cout << "\nHere is your sorted list:\n";
    for (int k = 0; k < length; ++k) {
        std::cout << "Name #" << k + 1 << ": " << names[k] << "\n";
    }
}
