//
// Created by pdzhambazov on 10.07.18.
//

#include "BlackJack.h"
#include "quiz82.h"
#include "Point2d.h"
#include "Monster.h"
#include "MonsterGenerator.h"

void runQuiz82();

void runQuiz83();

void runQuiz85();
void runQuiz85b();

void runFinalQuiz();
int main() {
//  runQuiz82();
//  runQuiz83();
//  runQuiz85();
//  runQuiz85b();
  runFinalQuiz();
}

void runFinalQuiz() {
//  Point2d first;
//  Point2d second(3.0, 4.0);
//  first.print();
//  second.print();
//
//  std::cout << "Distance between two points: " << first.distanceTo(second) << "\n";
//  std::cout << "Distance between two points 2: " << distanceFrom(second, first) << "\n";

//  Monster skele = MonsterGenerator::generateMonster();
//  skele.print();

//  const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
//  cardQueenHearts.printCard();
//  std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';
  Deck deck;
//  deck.printDeck();
//  std::cout << '\n';
//  std::cout << '\n';
  deck.shuffleDeck();
//  std::cout << '\n';
//  std::cout << '\n';
//  deck.printDeck();
  playBlackjack(deck);
}

void runQuiz83() {
  SimpleStack stack;
  stack.reset();
  stack.print();

  stack.push(5);
  stack.push(3);
  stack.push(8);

  stack.print();

  stack.pop();
  stack.print();
  stack.reset();

  stack.print();
}

void runQuiz82() {
  IntPair p1;
  p1.set(1, 1);

  IntPair p2{p1};

  IntPair p3{1, 2};
  p1.print();
  p2.print();
  p3.print();
}

void runQuiz85() {
  RGBA teal(0, 127, 127);
  teal.print();
}

void runQuiz85b() {
  Ball def;
  def.print();

  Ball blue("blue");
  blue.print();

  Ball twenty(20.0);
  twenty.print();

  Ball blueTwenty("blue", 20.0);
  blueTwenty.print();
}
