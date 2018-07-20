//
// Created by Petar Dzhambazov on 14.07.18.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "Fraction.h"
#include "Car.h"
#include "GradeMap.h"
#include "Matrix.h"
#include "Accumulator.h"
#include "MyString.h"
#include "Average.h"
#include "IntArray.h"
void runQuiz92a();
void runQuiz92b();
void runQuiz93();
void runQuiz96();
void runQuiz98();
void lesson99();
void runQuiz99();
void runFinalQuiz();
void runTwo();
void runThree();
IntArray fillArray();
void run106();
int main() {
//  runQuiz92a();
//  runQuiz92b();
//  runQuiz96();
//  runQuiz98();
//  lesson99();
//  runQuiz99();
//  runFinalQuiz();
  run106();
}
void run106() {
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i=0; i<10; i++)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int j=0; j<array.getLength(); j++)
        std::cout << array[j] << " ";
}
void runFinalQuiz() {
  runTwo();
  runThree();
}
void runThree() {
  IntArray a = fillArray();
  std::cout << a << '\n';

  IntArray b(1);
  a = a;
  b = a;

  std::cout << b << '\n';
}
IntArray fillArray() {
  IntArray a(5);
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}
void runTwo() {
  Average avg;

  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10; // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy = avg;
  std::cout << copy << '\n';
}
void runQuiz99() {
  MyString string("Hello, world!");
  std::cout << string(5, 7) << '\n'; // start at index 7 and return 5 characters
}

void lesson99() {
  Matrix matrix;
  matrix(1, 2) = 4.5;
  std::cout << matrix(1, 2) << '\n';
  matrix();
  std::cout << matrix(1, 2) << '\n';

  Accumulator acc;
  std::cout << acc(10) << '\n';
  std::cout << acc(20) << '\n';
}

void runQuiz98() {
  GradeMap grades;
  grades["Joe"] = 'A';
  grades["Frank"] = 'B';
  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
}
void runQuiz93() {
  Fraction f1;
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1*f2 << '\n';
}
void runQuiz96() {
  std::vector<Car> v;
  v.emplace_back("Toyota", "Corolla");
  v.emplace_back("Honda", "Accord");
  v.emplace_back("Toyota", "Camry");
  v.emplace_back("Honda", "Civic");

  std::sort(v.begin(), v.end()); // requires an overloaded operator<

  for (auto &car : v)
    std::cout << car << '\n'; // requires an overloaded operator<<
}
void runQuiz92b() {
  Fraction f1(2, 5);
  f1.print();

  Fraction f2(3, 8);
  f2.print();

  Fraction f3 = f1*f2;
  f3.print();

  Fraction f4 = f1*2;
  f4.print();

  Fraction f5 = 2*f2;
  f5.print();

  Fraction f6 = Fraction(1, 2)*Fraction(2, 3)*Fraction(3, 4);
  f6.print();
}
void runQuiz92a() {
  Fraction f1(1, 4);
  f1.print();

  Fraction f2(1, 2);
  f2.print();
}
