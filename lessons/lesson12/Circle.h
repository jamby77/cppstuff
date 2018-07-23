//
// Created by pdzhambazov on 23.07.18.
//

#ifndef IVA_CIRCLE_H
#define IVA_CIRCLE_H

#include "Point.h"
class Circle: public Shape {
int m_radius;
Point m_center;
 public:
  Circle(const Point &m_center, int m_radius);
  std::ostream &print(std::ostream &out) const override;
  int getRadius();
};

#endif //IVA_CIRCLE_H
