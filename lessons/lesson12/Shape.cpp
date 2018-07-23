//
// Created by pdzhambazov on 23.07.18.
//

#include "Shape.h"
Shape::~Shape() = default;
std::ostream &operator<<(std::ostream &out, const Shape &s) {
  return s.print(out);
}
