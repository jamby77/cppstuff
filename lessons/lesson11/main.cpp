//
// Created by Petar Dzhambazov on 21.07.18.
//

#include <iostream>
#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"
#include "Creature.h"
#include "Player.h"

void runQuiz114();
void runFinal3a();
void runFinal3b();
int main() {
  runQuiz114();
  runFinal3a();
  runFinal3b();
  return 0;
}
void runFinal3b() {
  std::cout << "Enter your name: ";
  std::string name;
  std::cin >> name;
  Player p(name);
  std::cout << "Welcome, " << p.getName() << ".\n";
  std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";
}
void runFinal3a() {
  Creature o("orc", 'o', 4, 2, 10);
  o.addGold(5);
  o.reduceHealth(1);
  std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold()
            << " gold.\n";

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
