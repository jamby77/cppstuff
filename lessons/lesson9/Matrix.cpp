//
// Created by pdzhambazov on 17.07.18.
//

#include <cassert>
#include "Matrix.h"
Matrix::Matrix() {
  init();
}
double &Matrix::operator()(int row, int col) {
  assert(col >= 0 && col < 4);
  assert(row >= 0 && row < 4);

  return data[row][col];
}
const double &Matrix::operator()(int row, int col) const {
  assert(col >= 0 && col < 4);
  assert(row >= 0 && row < 4);

  return data[row][col];
}
void Matrix::operator()() {
  init();
}
void Matrix::init() {
  for (auto &row : data) {
    for (double &col : row) {
      col = 0.0;
    }
  }
}
