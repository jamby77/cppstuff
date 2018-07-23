//
// Created by Petar Dzhambazov on 22.07.18.
//

#include "Monster.h"
int getRandomNumber(int min, int max);
Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]{
    {"dragon", 'D', 20, 4, 100},
    {"orc", 'o', 4, 2, 25},
    {"slime", 's', 1, 1, 10}
};
Monster::Monster(Monster::Type type) : Creature(monsterData[type].name,
                                                monsterData[type].symbol,
                                                monsterData[type].health,
                                                monsterData[type].damage,
                                                monsterData[type].gold) {}
Monster Monster::getRandomMonster() {
  return Monster(static_cast<Monster::Type>(getRandomNumber(0, Monster::MAX_TYPES-1)));
}

int getRandomNumber(int min, int max) {
  static const double fraction = 1.0/(static_cast<double >(RAND_MAX) + 1);
  return static_cast<int >(rand()*fraction*(max - min + 1) + min);
}
