#include <utility>
#include <cassert>

//
// Created by pdzhambazov on 17.07.18.
//

#include "MyString.h"
MyString::MyString(std::string s) : m_string{std::move(s)} {}
std::string MyString::operator()(int start, int len) {
  assert(start > 0 && start < m_string.length() - 1 && "MyString::operator(int, int): substring start should be "
                                                       "longer than 0 and less than string length");
  assert(len > 0 && start + len < m_string.length() && "MyString::operator(int, int): substring length should be "
                                                       "longer than 0 and less than string length");

  std::string temp;
  while (len--) {
    temp += m_string[start++];
  }
  return temp;
}
