//
// Created by pdzhambazov on 13.07.18.
//

#ifndef IVA_MONSTERGENERATOR_H
#define IVA_MONSTERGENERATOR_H

#include "Monster.h"
class MonsterGenerator {
 public:
  static Monster generateMonster();
  static int getRandomNumber(int min, int max);
};

#endif //IVA_MONSTERGENERATOR_H
