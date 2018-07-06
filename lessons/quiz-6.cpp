//
// Created by pdzhambazov on 06.07.18.
//

#include <iostream>
#include <algorithm>
#include <utility>
#include <ctime>
#include <random>
#include "quiz-6.h"

int items[3] = {0};

void initItems() {
    items[HEALTH_POTION] = 2;
    items[TORCH] = 5;
    items[ARROW] = 10;
}

int countTotalItems() {
    initItems();
    int total = 0;
    for (auto item : items) {
        total += item;
    }

    return total;
}

Student *initStudents(int size) {
    auto *students = new(std::nothrow) Student[size];
    if (!students) {
        return students;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter name and grade[Joe 82]: ";
        std::string name;
        int grade;
        std::cin >> name;
        std::cin >> grade;
        students[i] = {name, grade};
        clearStdin();
    }

    for (int startIdx = 0; startIdx < size - 1; ++startIdx) {
        int smallIdx = startIdx;
        for (int currIdx = startIdx + 1; currIdx < size; ++currIdx) {
            if (students[currIdx].grade > students[smallIdx].grade) {
                smallIdx = currIdx;
            }
        }
        std::swap(students[startIdx], students[smallIdx]);
    }
    return students;
}

void clearStdin() {
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(32767, '\n');
}

void printPhrase(char *phrase) {
    while (*phrase != '\0') {
        std::cout << *(phrase++) << ' ';
    }
}

void printCard(const Card &card) {
    switch (card.rank) {
        case RANK_2:
        case RANK_3:
        case RANK_4:
        case RANK_5:
        case RANK_6:
        case RANK_7:
        case RANK_8:
        case RANK_9:
        case RANK_10:
            std::cout << (card.rank + 2);
            break;
        case RANK_JACK:
            std::cout << 'J';
            break;
        case RANK_QUEEN:
            std::cout << 'Q';
            break;
        case RANK_KING:
            std::cout << 'K';
            break;
        case RANK_ACE:
            std::cout << 'A';
            break;
        case MAX_RANKS:
        default:
            std::cout << "WTF";
            break;
    }

    switch (card.suit) {
        case SUIT_CLUB:
            std::cout << 'C';
            break;
        case SUIT_HEART:
            std::cout << 'H';
            break;
        case SUIT_SPADE:
            std::cout << 'S';
            break;
        case SUIT_DIAMOND:
            std::cout << 'D';
            break;
        case MAX_SUITS:
        default:
            std::cout << "WTF";
            break;
    }
    std::cout << '\n';
}

std::array<Card, 52> buildDeck() {
    const auto i = 52;
    std::array<Card, i> deck{};
    const auto cardsInASuit = 13;
    for (int suit = 0; suit < MAX_SUITS; ++suit) {
        for (int rank = 0; rank < MAX_RANKS; ++rank) {
            int idx = (suit * cardsInASuit) + rank; // (0*13)+0|(1*13)+0
            deck[idx].rank = static_cast<CardRank >(rank);
            deck[idx].suit = static_cast<CardSuit >(suit);
        }
    }
    return deck;
}

void printDeck(const std::array<Card, 52> &deck) {
    for (Card c: deck) {
        printCard(c);
    }
    std::cout << '\n';
}

void swapCards(Card &card1, Card &card2) {
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void shuffleDeck(std::array<Card, 52> &deck) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_device rd;
    std::mt19937_64 mersenne(rd());
    std::uniform_int_distribution<> randomCard(0, 51);

    for (int i = 0; i < 52; ++i) {
        int shuffleIdx = randomCard(mersenne);
        swapCards(deck[i], deck[shuffleIdx]);
    }
}

int getCardValue(const Card &card) {
    int value{0};
    switch (card.rank) {
        case RANK_2:
        case RANK_3:
        case RANK_4:
        case RANK_5:
        case RANK_6:
        case RANK_7:
        case RANK_8:
        case RANK_9:
            value = static_cast<int>(card.rank);
            break;
        case RANK_10:
        case RANK_JACK:
        case RANK_QUEEN:
        case RANK_KING:
            value = 10;
            break;
        case RANK_ACE:
            value = 11;
            break;
        case MAX_RANKS:
        default:
            value = -1;
            break;
    }
    return value;
}

