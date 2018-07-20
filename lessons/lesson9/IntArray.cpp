//
// Created by pdzhambazov on 18.07.18.
//

#include <cassert>
#include "IntArray.h"
void IntArray::init(int size) {
  assert(size >= 0 && "IntArray: size should be more than 0");
  if (size == 0)
    m_int = nullptr;
  else
    m_int = new int[size];
}
IntArray::IntArray(int size) : m_size{size} {
  init(m_size);
}
int &IntArray::operator[](const int idx) {
  assertIndex(idx);
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

void IntArray::clear() {
  delete[] m_int;
  m_int = nullptr;
  m_size = 0;
}
void IntArray::reallocate(int len) {
  clear();
  init(len);
}
void IntArray::resize(int len) {
  if (len == m_size)
    return;

  if (len <= 0) {
    clear();
    return;
  }
  int *data = new int[len];

  if (m_size > 0) {
    int elementsToCopy = len > m_size ? m_size : len;
    for (int i = 0; i < elementsToCopy; ++i) {
      data[i] = m_int[i];
    }
  }
  delete[] m_int;
  m_int = data;
  m_size = len;
}
void IntArray::insertBefore(int value, int idx) {
  assertIndex(idx);
  int *data = new int[m_size + 1];
  for (int b = 0; b < idx; ++b) {
    data[b] = m_int[b];
  }
  data[idx] = value;
  for (int a = idx; a < m_size; ++a) {
    data[a + 1] = m_int[a];
  }

  delete[] m_int;
  m_int = data;
  m_size += 1;
}
void IntArray::remove(int idx) {
  assertIndex(idx);
  if (m_size == 1) {
    clear();
    return;
  }

  int *data = new int[m_size - 1];
  for (int b = 0; b < idx; ++b) {
    data[b] = m_int[b];
  }
  for (int a = idx; a < m_size; ++a) {
    data[a - 1] = m_int[a];
  }

  delete[] m_int;
  m_int = data;
  m_size -= 1;
}
IntArray::IntArray(const std::initializer_list<int> &list) : IntArray(static_cast<int>(list.size())) {
  int count = 0;
  for (auto &el : list) {
    m_int[count++] = el;
  }
}
