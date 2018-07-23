//
// Created by Petar Dzhambazov on 21.07.18.
//

#include "Banana.h"
#include <iostream>

Banana::Banana(const std::string &name, const std::string &color) : Fruit(name, color) {}
Banana::Banana(): Fruit("banana", "yellow") {}
std::ostream &operator<<(std::ostream &out, const Banana &b) {
  out << "Banana(\"" << b.getName() << "\", \"" << b.getColor() << "\")\n";
  return out;
}
