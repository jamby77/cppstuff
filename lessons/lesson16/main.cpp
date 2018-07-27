//
// Created by pdzhambazov on 27.07.18.
//

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <string>

template<typename T>
void display(T c) {
  auto it = c.begin();
  while (it != c.end()) {
    std::cout << *(it++) << " ";
  }
}

void itVect();
void itList();
void itSet();
void itMap();
int main() {
  itVect();
  std::cout << '\n';
  itList();
  std::cout << '\n';
  itSet();
  std::cout << '\n';
  itMap();
  std::cout << '\n';
  std::string string1 = std::string("0123456789abcde");
  std::cout << string1.length() << '\n';
  std::cout << string1.capacity() << '\n';
  string1 += "f";
  std::cout << string1.length() << '\n';
  std::cout << string1.capacity() << '\n';
  std::cout << '\n';
  std::cout << "Price:" << std::put_money(10.50L) << '\n';

  std::cout << std::cout.fill() << '\n';
  return 0;
}
void itMap() {
  using namespace std;
  map<int, string> m;
  m.insert(make_pair(4, "apple"));
  m.insert(make_pair(2, "orange"));
  m.insert(make_pair(1, "banana"));
  m.insert(make_pair(3, "grapes"));
  m.insert(make_pair(6, "mango"));
  m.insert(make_pair(5, "peach"));

  auto it = m.begin();
  while (it != m.end()){
    std::cout << it->first << '=' << it->second << ' ';
    it++;
  }
}
void itSet() {
  using std::set;
  set<int> s;
  s.insert(7);
  s.insert(2);
  s.insert(-6);
  s.insert(8);
  s.insert(1);
  s.insert(-4);

  display(s);
}
void itList() {
  using std::list;
  list<int> li;
  for (int i = 0; i < 10; ++i) {
    li.push_back(i);
  }
  display(li);
}
void itVect() {
  using std::vector;
  vector<int> v;
  v.reserve(10);
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  display(v);
}
