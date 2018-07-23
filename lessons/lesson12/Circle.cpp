//
// Created by pdzhambazov on 23.07.18.
//

#include "Circle.h"
Circle::Circle(const Point &m_center, int m_radius) : m_radius(m_radius), m_center(m_center) {}
std::ostream &Circle::print(std::ostream &out) const {
  out << "Circle(" << m_center << ", radius " << m_radius << ")";
  return out;
}
int Circle::getRadius() {
  return m_radius;
}
