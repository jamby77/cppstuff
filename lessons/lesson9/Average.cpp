//
// Created by pdzhambazov on 18.07.18.
//

#include "Average.h"
Average &Average::operator+=(int n) {
  m_count++;
  m_sum += n;
  return *this;
}
Average::Average(int n) : m_sum{n}, m_count{0} {}
std::ostream &operator<<(std::ostream &out, const Average &avg) {
  out << static_cast<double >(avg.m_sum) / avg.m_count;
  return out;
}
Average::Average(const Average &avg) : m_sum{avg.m_sum}, m_count{avg.m_count} {}
