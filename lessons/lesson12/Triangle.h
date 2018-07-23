//
// Created by pdzhambazov on 23.07.18.
//

#ifndef IVA_TRIANGLE_H
#define IVA_TRIANGLE_H

#include "Point.h"
class Triangle : public Shape{
 private:
  Point m_p1;
  Point m_p2;
  Point m_p3;
 public:
  Triangle(const Point &m_p1, const Point &m_p2, const Point &m_p3);
  std::ostream &print(std::ostream &out) const override;
};

#endif //IVA_TRIANGLE_H
