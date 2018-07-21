//
// Created by Petar Dzhambazov on 21.07.18.
//

#include "Creature.h"
const std::string &Creature::getName() const {
  return m_name;
}
Creature::Creature(const std::string &m_name, char m_symbol, int m_health, int m_damage, int m_gold)
    : m_name(m_name), m_symbol(m_symbol), m_health(m_health), m_damage(m_damage), m_gold(m_gold) {}
char Creature::getSymbol() const {
  return m_symbol;
}
int Creature::getHealth() const {
  return m_health;
}
int Creature::getDamage() const {
  return m_damage;
}
int Creature::getGold() const {
  return m_gold;
}
void Creature::reduceHealth(int health) {
  m_health -= health;
}
bool Creature::isDead() {
  return m_health <= 0;
}
void Creature::addGold(int gold) {
  m_gold += gold;
}
