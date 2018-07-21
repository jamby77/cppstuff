//
// Created by Petar Dzhambazov on 21.07.18.
//

#include <iostream>
#include "Apple.h"
#include "Banana.h"

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
}
