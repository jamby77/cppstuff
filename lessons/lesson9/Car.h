//
// Created by pdzhambazov on 17.07.18.
//

#ifndef IVA_CAR_H
#define IVA_CAR_H

#include <string>
class Car {
 private:
  std::string m_make;
  std::string m_model;

 public:
  Car(std::string make, std::string model);

  friend bool operator==(const Car &c1, const Car &c2);
  friend bool operator!=(const Car &c1, const Car &c2);
  friend bool operator<(const Car &c1, const Car &c2);
  friend std::ostream& operator<<(std::ostream &out, const Car &car);
};

#endif //IVA_CAR_H
