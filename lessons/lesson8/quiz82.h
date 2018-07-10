//
// Created by pdzhambazov on 10.07.18.
//

#ifndef IVA_QUIZ82_H
#define IVA_QUIZ82_H

#include <iostream>

class IntPair {
    int m_a{};
    int m_b{};
public:
    IntPair() : m_a{}, m_b{} {}
    IntPair(int a, int b) : m_a(a), m_b(b) {}
    IntPair(const IntPair &ip) {
        set(ip.m_a, ip.m_b);
    }

    void set(int a, int b) {
        m_a = a;
        m_b = b;
    }

    void print() {
        std::cout << "Pair(" << m_a << ", " << m_b << ")\n";
    }
};

#endif //IVA_QUIZ82_H
