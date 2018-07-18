//
// Created by pdzhambazov on 18.07.18.
//

#include <cassert>
#include "IntArray.h"
IntArray::IntArray(int size) : m_size{size} {
  assert(size > 0 && "IntArray: size should be more than 0");
  m_int = new int[size];
}
int &IntArray::operator[](const int idx) {
  assert(idx < m_size && "IntArray: subscript index too large");
  return m_int[idx];
}
std::ostream &operator<<(std::ostream &out, const IntArray &ia) {
  for (int i = 0; i < ia.m_size; ++i) {
    std::cout << ia.m_int[i] << ' ';
  }
  return out;
}
IntArray &IntArray::operator=(const IntArray &ia) {
  if (&ia == this) {
    return *this;
  }
  m_size = ia.m_size;
  if (ia.m_int) {
    delete[] m_int;
    m_int = new int[m_size];

    for (int i = 0; i < m_size; ++i) {
      m_int[i] = ia.m_int[i];
    }
  }
  return *this;
}
IntArray::~IntArray() {
  delete[] m_int;
}
IntArray::IntArray(const IntArray &ia) : m_size{ia.m_size} {
  if (ia.m_int) {
    m_int = new int[m_size];

    for (int i = 0; i < m_size; ++i) {
      m_int[i] = ia.m_int[i];
    }
  }
}
