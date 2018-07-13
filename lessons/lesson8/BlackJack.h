//
// Created by pdzhambazov on 13.07.18.
//

#ifndef IVA_BLACKJACK_H
#define IVA_BLACKJACK_H
#include <string>
#include <array>

class Card {
 public:
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
 private:
  CardRank m_rank;
  CardSuit m_suit;
 public:
  explicit Card(CardRank rank = RANK_ACE, CardSuit suit = SUIT_SPADE);
  void printCard() const;
  int getCardValue() const;
};
/*

enum class BlackjackResult {
  WIN_PLAYER,
  WIN_DEALER,
  TIE
};


typedef std::array<Card, 52> Deck;

Deck buildDeck();
void printDeck(const Deck &deck);

void swapCards(Card &card1, Card &card2);
void shuffleDeck(Deck &deck);

char getPlayerChoice();
BlackjackResult playBlackjack(const Deck &deck);
 */
class BlackJack {

};

#endif //IVA_BLACKJACK_H
