//
// Created by pdzhambazov on 23.07.18.
//

#include "Point.h"
Point::Point(int m_p1, int m_p2, int m_p3) : m_p1(m_p1), m_p2(m_p2), m_p3(m_p3) {}
std::ostream &Point::print(std::ostream &out) const {
  out << "Point(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
  return out;
}
