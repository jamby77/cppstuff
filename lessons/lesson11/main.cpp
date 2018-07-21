//
// Created by Petar Dzhambazov on 21.07.18.
//

#include <iostream>
#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"

void runQuiz114();
int main() {
  runQuiz114();
  return 0;
}
void runQuiz114() {
  const Apple a("Red delicious", "red", 4.2);
  std::cout << a;

  const Banana b("Cavendish", "yellow");
  std::cout << b;

  Apple ap("red");
  Banana ba;

  GrannySmith c;

  std::cout << "My " << ap.getName() << " is " << ap.getColor() << ".\n";
  std::cout << "My " << ba.getName() << " is " << ba.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}
