//
// Created by pdzhambazov on 13.07.18.
//

#include <random>
#include <ctime>
#include "MonsterGenerator.h"

Monster MonsterGenerator::generateMonster() {
  auto monsterType = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
  int hitPoints = getRandomNumber(1, 100);
  static std::string names[6] = {"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
  static std::string roars[6] = {"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
  auto name = names[getRandomNumber(0, 5)];
  auto roar = roars[getRandomNumber(0, 5)];
  return Monster(monsterType, name, roar, hitPoints);
}

int MonsterGenerator::getRandomNumber(int min, int max) {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::random_device rd;
  std::mt19937_64 mersenne(rd());
  std::uniform_int_distribution<> random(min, max);

  return random(mersenne);
}
