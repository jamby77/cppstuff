//
// Created by pdzhambazov on 04.07.18.
//

#include <iostream>
#include "dyn-array.h"
#include "quiz-6.h"

int main() {
//    int l = requestNamesLength();
//    std::string *names = requestNames(l);
//
//    sortNames(names, l);
//    printNames(names, l);

//    std::cout << "Total items: " << countTotalItems() << "\n";
//    int numStudents = 0;
//    do {
//        std::cout << "How many students? ";
//        std::cin >> numStudents;
//    } while (numStudents <= 1);
//    Student *students = initStudents(numStudents);
//
//    if (students) {
//        for (Student *i = students; i < students + numStudents; ++i) {
//            std::cout << i->firstName << " got a grade of " << i->grade << '\n';
//        }
//    }

//    char phrase[] = "Hello, World!";
//    printPhrase(phrase);
    auto deck = buildDeck();
    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}

