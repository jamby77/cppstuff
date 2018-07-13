

#include <iostream>

//
// Created by pdzhambazov on 13.07.18.
//

#include "Monster.h"
Monster::Monster(MonsterType monsterType, std::string name, std::string roar, int hitPoints) : m_type{monsterType},
                                                                                               m_name{std::move(name)},
                                                                                               m_roar{std::move(roar)},
                                                                                               m_hitPoints{hitPoints} {}
void Monster::print() {
  std::cout << m_name << " the " << getMonsterType() << " has " << m_hitPoints << " hit points and says " << m_roar;
}

std::string Monster::getMonsterType() {
  switch (m_type) {
    case Dragon: return "Dragon";
    case Goblin:return "Goblin";
    case Orge:return "Orge";
    case Orc:return "Orc";
    case Skeleton:return "Skeleton";
    case Troll:return "Troll";
    case Vampire:return "Vampire";
    case Zombie:return "Zombie";
    default:return "???";
  }
}
