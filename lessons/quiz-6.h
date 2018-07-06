//
// Created by pdzhambazov on 06.07.18.
//

#ifndef IVA_QUIZ_6_H
#define IVA_QUIZ_6_H

#include <string>
#include <array>

enum ItemTypes {
    HEALTH_POTION,
    TORCH,
    ARROW
};

struct Student {
    std::string firstName;
    int grade;
};

Student *initStudents(int size);

int countTotalItems();

void clearStdin();

void printPhrase(char *phrase);

enum CardSuit {
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};
enum CardRank {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

struct Card {
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card);
std::array<Card, 52> buildDeck();
void printDeck(const std::array<Card, 52> &deck);

void swapCards(Card &card1, Card &card2);
void shuffleDeck(std::array<Card, 52> &deck);

int getCardValue(const Card &card);
#endif //IVA_QUIZ_6_H
