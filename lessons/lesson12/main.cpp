//
// Created by pdzhambazov on 23.07.18.
//
#include <iostream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"
void runQuiz2();
int getLargestRadius(std::vector<Shape *> v);
int main() {
  runQuiz2();
  return 0;
}
void runQuiz2() {
  Circle c(Point(1, 2, 3), 7);
  std::cout << c << '\n';

  Triangle t(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9));
  std::cout << t << '\n';

  std::cout << "Vector part\n";
  std::vector<Shape *> v;
  v.push_back(new Circle(Point(1, 2, 3), 7));
  v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
  v.push_back(new Circle(Point(4, 5, 6), 3));

  // print each shape in vector v on its own line here
  for (auto const &item : v) {
    std::cout << *item << "\n";
  }

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

  for (auto const &item : v) {
    delete item;
  }
}
int getLargestRadius(std::vector<Shape *> v) {
  auto r{0};
  for (auto const &item : v) {
    auto *c = dynamic_cast<Circle *>(item);
    if (c && c->getRadius() > r) {
      r = c->getRadius();
    }
  }
  return r;
}
