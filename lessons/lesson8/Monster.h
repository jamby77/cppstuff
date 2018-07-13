//
// Created by pdzhambazov on 13.07.18.
//

#ifndef IVA_MONSTER_H
#define IVA_MONSTER_H

#include <string>
class Monster {
 public:
  enum MonsterType {
    Dragon,
    Goblin,
    Orge,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    MAX_MONSTER_TYPES
  };
 private:
  MonsterType m_type;
  std::string m_name;
  std::string m_roar;
  int m_hitPoints;
};

#endif //IVA_MONSTER_H
