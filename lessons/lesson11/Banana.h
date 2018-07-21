//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_BANANA_H
#define IVA_BANANA_H

#include "Fruit.h"
class Banana : public Fruit {
 public:
  Banana();
  Banana(const std::string &name, const std::string &color);
  friend std::ostream &operator<<(std::ostream &out, const Banana &b);
};

#endif //IVA_BANANA_H
