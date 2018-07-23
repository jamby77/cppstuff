//
// Created by Petar Dzhambazov on 21.07.18.
//

#include "Fruit.h"
Fruit::Fruit(const std::string &name, const std::string &color) : m_name{name}, m_color{color} {}

std::string Fruit::getName() const {
  return m_name;
}
std::string Fruit::getColor() const {
  return m_color;
}
