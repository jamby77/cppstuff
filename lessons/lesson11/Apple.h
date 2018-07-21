//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_APPLE_H
#define IVA_APPLE_H

#include "Fruit.h"
class Apple : public Fruit {
  double m_fiber = 0.0;
 public:
  Apple(const std::string &color);
  Apple(const std::string &name, const std::string &color, double fiber);
  friend std::ostream& operator<<(std::ostream &out, const Apple &a);
};

#endif //IVA_APPLE_H
