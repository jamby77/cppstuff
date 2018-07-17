//
// Created by Petar Dzhambazov on 14.07.18.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "Fraction.h"
#include "Car.h"
void runQuiz92a();
void runQuiz92b();
void runQuiz96();
int main(){
  runQuiz92a();
  runQuiz92b();
  runQuiz96();
}
void runQuiz96() {
  std::vector<Car> v;
  v.push_back(Car("Toyota", "Corolla"));
  v.push_back(Car("Honda", "Accord"));
  v.push_back(Car("Toyota", "Camry"));
  v.push_back(Car("Honda", "Civic"));

  std::sort(v.begin(), v.end()); // requires an overloaded operator<

  for (auto &car : v)
    std::cout << car << '\n'; // requires an overloaded operator<<
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