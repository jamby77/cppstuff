//
// Created by pdzhambazov on 17.07.18.
//

#include "Accumulator.h"
Accumulator::Accumulator() = default;
int Accumulator::operator()(int i) {
  return (m_counter += i);
}
