//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_CREATURE_H
#define IVA_CREATURE_H

#include <string>
class Creature {
 public:
  Creature(const std::string &m_name, char m_symbol, int m_health, int m_damage, int m_gold);
  const std::string &getName() const;
  char getSymbol() const;
  int getHealth() const;
  int getDamage() const;
  int getGold() const;
  void reduceHealth(int health);
  bool isDead();
  void addGold(int gold);
 private:
  std::string m_name;
  char m_symbol;
  int m_health;
  int m_damage;
  int m_gold;
};

#endif //IVA_CREATURE_H
