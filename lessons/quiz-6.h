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

enum class BlackjackResult {
    WIN_PLAYER,
    WIN_DEALER,
    TIE
};

struct Card {
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card);
typedef std::array<Card, 52> Deck;

Deck buildDeck();
void printDeck(const Deck &deck);

void swapCards(Card &card1, Card &card2);
void shuffleDeck(Deck &deck);

int getCardValue(const Card &card);
char getPlayerChoice();
BlackjackResult playBlackjack(const Deck &deck);
#endif //IVA_QUIZ_6_H
