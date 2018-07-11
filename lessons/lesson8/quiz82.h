//
// Created by pdzhambazov on 10.07.18.
//

#ifndef IVA_QUIZ82_H
#define IVA_QUIZ82_H

#include <iostream>
#include <array>

class IntPair {
  int m_a{};
  int m_b{};
 public:
  IntPair() : m_a{}, m_b{} {}

  IntPair(int a, int b) : m_a(a), m_b(b) {}

  IntPair(const IntPair &ip);

  void set(int a, int b);

  void print();
};

class SimpleStack {
  std::array<int, 10> m_stack;
  int m_length{};
 public:
  SimpleStack() : m_stack{}, m_length{} {};

  void reset();

  bool push(int a);

  int pop();

  void print();
};

class RGBA {
  std::uint8_t m_red;
  std::uint8_t m_green;
  std::uint8_t m_blue;
  std::uint8_t m_alpha;
 public:
  explicit RGBA(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255)
      : m_red{r}, m_green{g}, m_blue{b}, m_alpha{a} {};

  void print();
};

class Ball {
 private:
  std::string m_color = "black";
  double m_radius = 10.0;

 public:
  // Default constructor with no parameters
  Ball() = default;

  // Constructor with only color parameter (radius will use default value)
  Ball(const std::string &color) {
    m_color = color;
  }

  // Constructor with only radius parameter (color will use default value)
  Ball(double radius) {
    m_radius = radius;
  }

  // Constructor with both color and radius parameters
  Ball(const std::string &color, double radius) {
    m_color = color;
    m_radius = radius;
  }

  void print() {
    std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
  }
};

#endif //IVA_QUIZ82_H
