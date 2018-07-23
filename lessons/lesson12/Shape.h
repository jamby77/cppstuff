//
// Created by pdzhambazov on 23.07.18.
//

#ifndef IVA_SHAPE_H
#define IVA_SHAPE_H

#include <iostream>
class Shape {
 public:
  virtual std::ostream &print(std::ostream &out) const = 0;
  friend std::ostream &operator<<(std::ostream &out, const Shape &s);
  virtual ~Shape();
};

#endif //IVA_SHAPE_H
