//
// Created by pdzhambazov on 04.07.18.
//

#ifndef IVA_DYN_ARRAY_H
#define IVA_DYN_ARRAY_H

#include <string>

int requestNamesLength();
std::string *requestNames(int namesLength);
void sortNames(std::string *names, int length);
void printNames(std::string *names, int length);

#endif //IVA_DYN_ARRAY_H
