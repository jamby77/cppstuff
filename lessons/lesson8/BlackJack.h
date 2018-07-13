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

class Deck {
 private:
  std::array<Card, 52> m_deck;
  int m_cardIndex = 0;
  static void swapCards(Card &card1, Card &card2);
 public:
  Deck();
  void printDeck() const;
  void shuffleDeck();
  Card& dealCard();
};

enum class BlackjackResult {
  WIN_PLAYER,
  WIN_DEALER,
  TIE
};

char getPlayerChoice();
BlackjackResult playBlackjack( Deck &deck);

#endif //IVA_BLACKJACK_H
