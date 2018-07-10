//
// Created by pdzhambazov on 10.07.18.
//

#ifndef IVA_QUIZ82_H
#define IVA_QUIZ82_H

#include <iostream>

class IntPair {
public:
    int m_a;
    int m_b;

    void set(int a, int b) {
        m_a = a;
        m_b = b;
    }

    void print() {
        std::cout << "Pair(" << m_a << ", " << m_b << ")\n";
    }
};

#endif //IVA_QUIZ82_H
