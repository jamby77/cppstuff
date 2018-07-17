//
// Created by pdzhambazov on 17.07.18.
//

#ifndef IVA_MYSTRING_H
#define IVA_MYSTRING_H

#include <string>
class MyString {
std::string m_string = "";
 public:
  MyString(std::string s);
  std::string operator()(int start, int len);
};

#endif //IVA_MYSTRING_H
