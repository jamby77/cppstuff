//
// Created by Petar Dzhambazov on 21.07.18.
//

#include "Apple.h"
#include <iostream>

Apple::Apple(const std::string &name, const std::string &color, double fiber) : Fruit(name, color), fiber{fiber} {}
std::ostream &operator<<(std::ostream &out, const Apple &a) {
  out << "Apple(\"" << a.getName() << "\", \"" << a.getColor() << "\", " << a.fiber << ")\n";
  return out;
}
