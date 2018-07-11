//
// Created by pdzhambazov on 10.07.18.
//

#include "quiz82.h"

void runQuiz82();

void runQuiz83();
void runQuiz85();

int main() {
    runQuiz82();
    runQuiz83();
    runQuiz85();
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
