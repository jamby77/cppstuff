//
// Created by pdzhambazov on 18.07.18.
//

#ifndef IVA_INTARRAY_H
#define IVA_INTARRAY_H

#include <iostream>
#include <cassert>
class IntArray {
  int *m_int = nullptr;
  int m_size = 0;
  void init(int size);
  void assertIndex(int idx) { assert(idx >= 0 && idx <= m_size && "IntArray: subscript index too large"); }
 public:
  explicit IntArray(int size);
  IntArray(const IntArray &ia);
  IntArray(const std::initializer_list<int> &list);
  ~IntArray();
  int getLength() { return m_size; }
  void clear();
  void reallocate(int len);
  void resize(int len);
  void insertBefore(int value, int idx);
  void insertAtBeginning(int value) { insertBefore(value, 0); };
  void insertAtEnd(int value) { insertBefore(value, m_size); };
  void remove(int idx);
  int &operator[](const int idx);
  IntArray &operator=(const IntArray &ia);
  friend std::ostream &operator<<(std::ostream &out, const IntArray &ia);
};

#endif //IVA_INTARRAY_H
