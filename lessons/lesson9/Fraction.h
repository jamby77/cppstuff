//
// Created by Petar Dzhambazov on 14.07.18.
//

#ifndef IVA_FRACTION_H
#define IVA_FRACTION_H

class Fraction {
int m_num;
int m_denom;
 public:
  Fraction(int numerator = 1, int denominator = 1);
  void print();
  friend Fraction operator*(Fraction f1, Fraction f2);
  friend Fraction operator*(Fraction f, int n);
  friend Fraction operator*(int n, Fraction f);
 private:
  int gcd(int a, int b);
  void reduce();
};

#endif //IVA_FRACTION_H
