//
// Created by pdzhambazov on 10.07.18.
//

#include <cassert>
#include "quiz82.h"

IntPair::IntPair(const IntPair &ip) {
  set(ip.m_a, ip.m_b);
}

void IntPair::set(int a, int b) {
  m_a = a;
  m_b = b;
}

void IntPair::print() {
  std::cout << "Pair(" << m_a << ", " << m_b << ")\n";
}

// simple stack
void SimpleStack::reset() {
  m_stack = {};
  m_length = 0;
}

bool SimpleStack::push(int a) {
  if (m_stack.size() == m_length) {
    return false;
  }
  m_stack[m_length++] = a;
  return true;
}

int SimpleStack::pop() {
  assert(m_length > 0);
  int a = m_stack[m_length--];
  return a;
}

void SimpleStack::print() {
  std::cout << "(";
  for (int i = 0; i < m_length; ++i) {
    std::cout << " " << m_stack[i];
  }
  std::cout << " )\n";
}

void RGBA::print() {
  std::cout << "\nr=" << static_cast<int >(m_red) << " g=" << static_cast<int >(m_green) << " b="
            << static_cast<int >(m_blue) << " a=" << static_cast<int >(m_alpha) << "\n\n";
}
