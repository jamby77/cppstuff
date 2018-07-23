//
// Created by pdzhambazov on 23.07.18.
//

#include "Triangle.h"
Triangle::Triangle(const Point &m_p1, const Point &m_p2, const Point &m_p3) : m_p1(m_p1), m_p2(m_p2), m_p3(m_p3) {}
std::ostream &Triangle::print(std::ostream &out) const {
  out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
  return out;
}
