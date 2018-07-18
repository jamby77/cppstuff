//
// Created by pdzhambazov on 18.07.18.
//

#ifndef IVA_INTARRAY_H
#define IVA_INTARRAY_H

#include <iostream>
class IntArray {
  int *m_int = nullptr;
  int m_size = 0;
 public:
  explicit IntArray(int size);
  IntArray(const IntArray &ia);
  ~IntArray();
  int &operator[](const int idx);
  IntArray &operator=(const IntArray &ia);
  friend std::ostream &operator<<(std::ostream &out, const IntArray &ia);
};

#endif //IVA_INTARRAY_H
