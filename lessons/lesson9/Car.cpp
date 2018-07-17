//
// Created by pdzhambazov on 17.07.18.
//
#include <iostream>
#include "Car.h"
Car::Car(std::string make, std::string model)
    : m_make{std::move(make)}, m_model{std::move(model)} {
}

bool operator==(const Car &car1, const Car &car2) {
  return (car1.m_make == car2.m_make) && (car1.m_model == car2.m_model);
}
bool operator!=(const Car &c1, const Car &c2) {
  return !(c1 == c2);
}
std::ostream &operator<<(std::ostream &out, const Car &car) {
  out << '(' << car.m_make << ", " << car.m_model << ")\n";
  return out;
}
bool operator<(const Car &c1, const Car &c2) {
  return (c1.m_make == c2.m_make) ? (c1.m_model < c2.m_model) : c1.m_make < c2.m_make;
}
