//
// Created by pdzhambazov on 25.07.18.
//

#ifndef IVA_PAIR1_H
#define IVA_PAIR1_H
template<class T>
class Pair1 {
  T m_a;
  T m_b;
 public:
  Pair1(T a, T b) : m_a{a}, m_b{b} {}
  T &first() { return m_a; }
  const T &first() const { return m_a; }
  T &second() { return m_b; }
  const T &second() const { return m_b; }
};
#endif //IVA_PAIR1_H
