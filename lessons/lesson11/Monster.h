//
// Created by Petar Dzhambazov on 22.07.18.
//

#ifndef IVA_MONSTER_H
#define IVA_MONSTER_H

#include "Creature.h"
class Monster : public Creature {
 public:
  struct MonsterData {
    std::string name;
    char symbol;
    int health;
    int damage;
    int gold;
  };
  enum Type {
    DRAGON, ORC, SLIME, MAX_TYPES
  };
  static MonsterData monsterData[MAX_TYPES];
  static Monster getRandomMonster();
  Monster(Type type);
};

#endif //IVA_MONSTER_H
