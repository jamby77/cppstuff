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
    shuffleDeck(deck);
    BlackjackResult res = playBlackjack(deck);
    std::cout << "\n\n\tResults:\n";
    switch (res) {
        case BlackjackResult::WIN_DEALER:
            std::cout << "Dealer wins\n";
            break;
        case BlackjackResult::WIN_PLAYER:
            std::cout << "Player wins\n";
            break;
        default:
            std::cout << "It is a tie";
    }
    return 0;
}

