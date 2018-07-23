//
// Created by Petar Dzhambazov on 21.07.18.
//

#include <iostream>
#include "Player.h"
Player::Player(const std::string &m_name) :
    Creature(m_name, '@', 10, 1, 0) {}
void Player::levelUp() {
  m_level++;
  addDamage(1);
  std::cout << "You are now level " << m_level << ".\n";
}
