//
// Created by Petar Dzhambazov on 21.07.18.
//

#include <iostream>
#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

void runQuiz114();
void runFinal3a();
void runFinal3b();
void runFinal3c();
void runFinal3e();
void playGame();
void fightMonster(Player &p, Monster &m);
void attackMonster(Player &p, Monster &m);
void attackPlayer(Monster &m, Player &p);

int main() {
//  runQuiz114();
//  runFinal3a();
//  runFinal3b();
//  runFinal3c();
//  runFinal3e();
  playGame();
  return 0;
}

int getRandomNumber2(int min, int max) {
  static const double fraction = 1.0/(static_cast<double >(RAND_MAX) + 1);
  return static_cast<int >(rand()*fraction*(max - min + 1) + min);
}
void playGame() {
  std::cout << "Enter your name: ";
  std::string name;
  std::cin >> name;
  Player p(name);
  std::cout << "Welcome, " << p.getName() << ".\n";
  while (true) {
    Monster m = Monster::getRandomMonster();
    fightMonster(p, m);
    if (p.isDead() || p.getLevel()==20) {
      break;
    }
  }
}

void fightMonster(Player &p, Monster &m) {
  std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")\n";
  while (!m.isDead() && !p.isDead()) {
    std::cout << "(R)un or (F)ight: ";
    char choice;
    std::cin >> choice;
    if (choice=='f' || choice=='F') {
      attackMonster(p, m);
      if (!m.isDead()) {
        attackPlayer(m, p);
      }
    } else {
      if (getRandomNumber2(0, 1)) {
        std::cout << "You successfully fled.\n";
        break;
      } else {
        std::cout << "You failed to flee.\n";
        attackPlayer(m, p);
      }
    }
  }
}

void attackMonster(Player &p, Monster &m) {
  m.reduceHealth(p.getDamage());
  std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
  if (m.isDead()) {
    std::cout << "You killed the " << m.getName() << ".\n";
    p.levelUp();
    p.addGold(m.getGold());
  }
}
void attackPlayer(Monster &m, Player &p) {
  if (!getRandomNumber2(0, 1)) {
    std::cout << m.getName() << " missed\n";
    return;
  }
  p.reduceHealth(m.getDamage());
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
  if (p.isDead()) {
    std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold()
              << " gold.\nToo bad you can't take it with you!";
  }
}
void runFinal3e() {
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand(); // get rid of first result

  for (int i = 0; i < 10; ++i) {
    Monster m = Monster::getRandomMonster();
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
  }
}
void runFinal3c() {
  Monster m(Monster::ORC);
  std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
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
