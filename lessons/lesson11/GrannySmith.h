//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_GRANNYSMITH_H
#define IVA_GRANNYSMITH_H

#include "Apple.h"
class GrannySmith: public Apple {
 public:
  GrannySmith();
  std::string getName() {
    return "granny smith " + Apple::getName();
  }
};

#endif //IVA_GRANNYSMITH_H
