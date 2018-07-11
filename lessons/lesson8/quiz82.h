//
// Created by pdzhambazov on 10.07.18.
//

#ifndef IVA_QUIZ82_H
#define IVA_QUIZ82_H

#include <iostream>
#include <array>

class IntPair {
    int m_a{};
    int m_b{};
public:
    IntPair() : m_a{}, m_b{} {}

    IntPair(int a, int b) : m_a(a), m_b(b) {}

    IntPair(const IntPair &ip);

    void set(int a, int b);

    void print();
};

class SimpleStack {
    std::array<int, 10> m_stack;
    int m_length{};
public:
    SimpleStack(): m_stack{}, m_length{} {};
    void reset();
    bool push(int a);
    int pop();
    void print();
};

#endif //IVA_QUIZ82_H
