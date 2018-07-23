//
// Created by pdzhambazov on 23.07.18.
//

#ifndef IVA_POINT_H
#define IVA_POINT_H

#include "Shape.h"
#include <iostream>

class Point: public Shape {
int m_p1 = 0;
int m_p2 = 0;
int m_p3 = 0;
 public:
  Point(int m_p1, int m_p2, int m_p3);
  std::ostream& print(std::ostream &out) const override;
};

#endif //IVA_POINT_H
