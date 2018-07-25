//
// Created by pdzhambazov on 25.07.18.
//

#include <iostream>
#include "Pair1.h"
#include "Pair.h"
void runQuiz1();
void runQuiz2();
void runQuiz3();
int main() {
  runQuiz1();
  runQuiz2();
  runQuiz3();
  return 0;
}
void runQuiz3() {
  StringValuePair<int> svp("Hello", 5);
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}

void runQuiz2() {
  Pair<int, double> p1(5, 6.7);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair<double, int> p2(2.3, 4);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
void runQuiz1() {
  Pair1<int> p1(5, 8);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2(2.3, 4.5);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
