//
// Created by Petar Dzhambazov on 14.07.18.
//

#include <iostream>
#include "Fraction.h"
Fraction::Fraction(int numerator, int denominator) : m_num{numerator}, m_denom{denominator} {
  if (m_denom == 0) {
    throw std::runtime_error("Your fraction has an invalid denominator.");
  }
  reduce();
}
void Fraction::print() {
  std::cout << m_num << "/" << m_denom << '\n';
}
Fraction operator*(Fraction f1, Fraction f2) {
  return Fraction(f1.m_num*f2.m_num, f1.m_denom*f2.m_denom);
}
Fraction operator*(Fraction f, int n) {
  return Fraction(f.m_num*n, f.m_denom);
}
Fraction operator*(int n, Fraction f) {
  return f*n;
}

int Fraction::gcd(int a, int b) {
  return (b==0) ? (a > 0 ? a : -a) : gcd(b, a%b);
}
void Fraction::reduce() {
  int commonDenom = gcd(m_num, m_denom);
  m_num = m_num/commonDenom;
  m_denom = m_denom/commonDenom;
}
std::ostream &operator<<(std::ostream &out, const Fraction &f) {
  out << f.m_num << "/" << f.m_denom << '\n';
  return out;
}
std::istream &operator>>(std::istream &in, Fraction &f) {
  in >> f.m_num;
  in >> f.m_denom;
  return in;
}

