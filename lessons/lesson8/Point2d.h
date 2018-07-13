//
// Created by pdzhambazov on 13.07.18.
//

#ifndef IVA_POINT2D_H
#define IVA_POINT2D_H

class Point2d {
 private:
  double m_x;
  double m_y;
 public:
  explicit Point2d(double x = 0.0, double y = 0.0);
  void print();
  double distanceTo(const Point2d &p) const;
  friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

#endif //IVA_POINT2D_H
