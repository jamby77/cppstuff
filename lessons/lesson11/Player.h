//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_PLEAYER_H
#define IVA_PLEAYER_H

#include "Creature.h"
class Player: public Creature {
 private:
  int m_level = 1;
 public:
  int getLevel() const {
    return m_level;
  }
 public:
  Player(const std::string &m_name);
  void levelUp();
};

#endif //IVA_PLEAYER_H
