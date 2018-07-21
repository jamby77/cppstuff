//
// Created by Petar Dzhambazov on 21.07.18.
//

#ifndef IVA_FRUIT_H
#define IVA_FRUIT_H

#include <string>
class Fruit {
  std::string m_name = "";
  std::string m_color = "white";
 public:
  Fruit(const std::string &name, const std::string &color);
  std::string getName() const;
  std::string getColor() const;
};

#endif //IVA_FRUIT_H
