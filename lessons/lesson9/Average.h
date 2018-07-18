//
// Created by pdzhambazov on 18.07.18.
//

#ifndef IVA_AVERAGE_H
#define IVA_AVERAGE_H

#include <cstdint>
#include <iostream>
class Average {
  int32_t m_sum;
  int8_t m_count;
 public:
  Average(int n = 0);
  Average(const Average &avg);
  Average &operator+=(int n);
  friend std::ostream& operator<<(std::ostream &out, const Average &avg);
};

#endif //IVA_AVERAGE_H
