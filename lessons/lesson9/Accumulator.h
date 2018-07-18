//
// Created by pdzhambazov on 17.07.18.
//

#ifndef IVA_ACCUMULATOR_H
#define IVA_ACCUMULATOR_H

class Accumulator {
int m_counter = 0;
 public:
  Accumulator();
  int operator()(int i);
};

#endif //IVA_ACCUMULATOR_H
