//
// Created by Petar Dzhambazov on 22.07.18.
//

#ifndef IVA_MONSTER_H
#define IVA_MONSTER_H

#include "Creature.h"
class Monster : public Creature {
  enum Type {
    DRAGON, ORC, SLIME, MAX_TYPES
  };
};

#endif //IVA_MONSTER_H
