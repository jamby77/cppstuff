//
// Created by Petar Dzhambazov on 14.07.18.
//

#include "Fraction.h"
void runQuiz92a();
void runQuiz92b();
int main(){
  runQuiz92a();
  runQuiz92b();
}
void runQuiz92b() {
  Fraction f1(2, 5);
  f1.print();

  Fraction f2(3, 8);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 2;
  f4.print();

  Fraction f5 = 2 * f2;
  f5.print();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();
}
void runQuiz92a() {
  Fraction f1(1, 4);
  f1.print();

  Fraction f2(1, 2);
  f2.print();
}