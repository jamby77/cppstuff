//
// Created by pdzhambazov on 26.07.18.
//
#include <iostream>
#include "Timer.h"
#include "DynamicArray.h"
void example1();
DynamicArray<int> cloneArrayAndDouble(DynamicArray<int> &arr);
int main() {
  example1();
  return 0;
}
void example1() {
  Timer t;
  for (int j = 0; j < 10; ++j) {
    DynamicArray<int> arr(1000000);
    for (int i = 0, c = arr.getLength(); i < c; ++i) {
      arr[i] = i;
    }

    arr = cloneArrayAndDouble(arr);
  }

  std::cout << t.elapsed();
}
DynamicArray<int> cloneArrayAndDouble(DynamicArray<int> &arr) { // V5$$9rQ9zlNG
  DynamicArray<int> dbl(arr.getLength());

  for (int i = 0, c = arr.getLength(); i < c; ++i) {
    dbl[i] = arr[i] * 2;
  }

  return dbl;
}
