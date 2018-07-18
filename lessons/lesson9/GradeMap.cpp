//
// Created by pdzhambazov on 17.07.18.
//

#include "GradeMap.h"
GradeMap::GradeMap() = default;
grade_t &GradeMap::operator[](const std::string name) {
  for (auto &student : m_map) {
    if (student.name == name) {
      return student.grade;
    }
  }
  StudentGrade t = {name, ' '};
  m_map.push_back(t);
  return m_map.back().grade;
}
