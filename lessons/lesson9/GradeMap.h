//
// Created by pdzhambazov on 17.07.18.
//

#ifndef IVA_GRADEMAP_H
#define IVA_GRADEMAP_H
#include <string>
#include <vector>
using grade_t = char;
struct StudentGrade {
  std::string name;
  grade_t grade;
};

class GradeMap {
 private:
  std::vector<StudentGrade> m_map;
 public:
  GradeMap();
  grade_t& operator[](const std::string name);
};

#endif //IVA_GRADEMAP_H
