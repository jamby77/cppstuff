//
// Created by pdzhambazov on 25.07.18.
//

#ifndef IVA_PAIR_H
#define IVA_PAIR_H
#include <string>

template<class T, class S>
class Pair {
  T m_a;
  S m_b;
 public:
  Pair(T a, S b) : m_a{a}, m_b{b} {}
  T &first() { return m_a; }
  const T &first() const { return m_a; }
  S &second() { return m_b; }
  const S &second() const { return m_b; }
};

template <class S>
class StringValuePair: public Pair<std::string, S>{
 public:
  StringValuePair(const std::string &a, const S &b) : Pair<std::string, S>(a, b) {}
};
#endif //IVA_PAIR_H
