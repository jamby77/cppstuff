//
// Created by pdzhambazov on 13.07.18.
//

#include <iostream>
#include <cmath>
#include "Point2d.h"

Point2d::Point2d(double x, double y) : m_x{x}, m_y{y} {}
void Point2d::print() {
  std::cout << "Point2d(" << m_x << ", " << m_y << ");\n";
}

double Point2d::distanceTo(const Point2d &p) const {
  return sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}

double distanceFrom(const Point2d &p1, const Point2d &p2) {
  return sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}
Point2d::~Point2d() {
//  delete[] m_data;
}
