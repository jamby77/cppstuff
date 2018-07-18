//
// Created by pdzhambazov on 17.07.18.
//

#ifndef IVA_MATRIX_H
#define IVA_MATRIX_H

class Matrix {
 private:
  double data[4][4];
  void init();
 public:
  Matrix();
  void operator()();
  double &operator()(int row, int col);
  const double &operator()(int row, int col) const;
};

#endif //IVA_MATRIX_H
