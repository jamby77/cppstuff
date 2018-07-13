//
// Created by pdzhambazov on 13.07.18.
//

#include <iostream>
#include <random>
#include <ctime>
#include "BlackJack.h"
/*

void printCard(const Card &card) {
  std::string desc;
  switch (card.rank) {
    case RANK_2:
    case RANK_3:
    case RANK_4:
    case RANK_5:
    case RANK_6:
    case RANK_7:
    case RANK_8:
    case RANK_9:
    case RANK_10:desc.append(std::to_string(card.rank + 2));
      break;
    case RANK_JACK:desc.append("J");
      break;
    case RANK_QUEEN:desc.append("Q");
      break;
    case RANK_KING:desc.append("K");
      break;
    case RANK_ACE:desc.append("A");
      break;
    case MAX_RANKS:
    default:desc.append("WTF");
      break;
  }
//    desc.append(" ");
  switch (card.suit) {
    case SUIT_CLUB:desc.append("♣");
      break;
    case SUIT_HEART:desc.append("♥");
      break;
    case SUIT_SPADE:desc.append("♠");
      break;
    case SUIT_DIAMOND:desc.append("♠");
      break;
    case MAX_SUITS:
    default:desc.append("WTF");
      break;
  }
  std::cout << desc << '\n';
}

Deck buildDeck() {
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

void printDeck(const Deck &deck) {
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

void shuffleDeck(Deck &deck) {
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
    case RANK_9:value = static_cast<int>(card.rank) + 2;
      break;
    case RANK_10:
    case RANK_JACK:
    case RANK_QUEEN:
    case RANK_KING:value = 10;
      break;
    case RANK_ACE:value = 11;
      break;
    case MAX_RANKS:
    default:value = -1;
      break;
  }
  return value;
}

void printTurn(const std::string &player, const Card &card) {
  std::cout << player << ": ";
  printCard(card);
}

BlackjackResult playBlackjack(const Deck &deck) {
  const Card *cardPtr = &deck[0];
  int totalPlayer = 0,
      totalDealer = 0;

  const auto dealer = "Dealer";
  const auto player = "Player";

  printTurn(dealer, *cardPtr);
  totalDealer += getCardValue(*(cardPtr++)); // dealer first card

  printTurn(player, *cardPtr);
  totalPlayer += getCardValue(*(cardPtr++)); // player first card
  printTurn(player, *cardPtr);
  totalPlayer += getCardValue(*(cardPtr++)); // player second card

  while (true) {
    std::cout << "Player total: " << totalPlayer << "\n";
    if (getPlayerChoice() == 's')
      break;
    // hit
    printTurn(player, *cardPtr);
    auto cardValue = getCardValue(*(cardPtr++));
    if (cardValue == 11 && (totalPlayer + cardValue) > 21) {
      // if it is an ace and value 11 will make it go over 21, count it as 1
      cardValue = 1;
    }
    totalPlayer += cardValue;
    if (totalPlayer > 21) {
      break;
    }
  }
  std::cout << "Player total: " << totalPlayer << "\n";
  // stand
  if (totalPlayer > 21) {
    // if score over 21, player looses
    return BlackjackResult::WIN_DEALER;
  }

  while (totalDealer < 17) {
    // hit
    printTurn(dealer, *cardPtr);
    totalDealer += getCardValue(*(cardPtr++));
  }
  std::cout << "Dealer total: " << totalDealer << "\n";
  // stand
  if (totalDealer > 21) {
    // if score over 21, dealer looses
    return BlackjackResult::WIN_PLAYER;
  }
  return totalPlayer > totalDealer ? BlackjackResult::WIN_PLAYER :
         (totalPlayer == totalDealer) ? BlackjackResult::TIE
                                      : BlackjackResult::WIN_DEALER;
}

char getPlayerChoice() {
  std::cout << "(h) to hit, (s) to stand: ";

  char choice;
  do {
    std::cin >> choice;
  } while (choice != 'h' && choice != 's');
  return choice;
}

*/
Card::Card(Card::CardRank rank, Card::CardSuit suit) : m_rank{rank}, m_suit{suit} {}
void Card::printCard() const {
  std::string desc;
  switch (m_rank) {
    case RANK_2:
    case RANK_3:
    case RANK_4:
    case RANK_5:
    case RANK_6:
    case RANK_7:
    case RANK_8:
    case RANK_9:
    case RANK_10:desc.append(std::to_string(m_rank + 2));
      break;
    case RANK_JACK:desc.append("J");
      break;
    case RANK_QUEEN:desc.append("Q");
      break;
    case RANK_KING:desc.append("K");
      break;
    case RANK_ACE:desc.append("A");
      break;
    case MAX_RANKS:
    default:desc.append("WTF");
      break;
  }
//    desc.append(" ");
  switch (m_suit) {
    case SUIT_CLUB:desc.append("♣");
      break;
    case SUIT_HEART:desc.append("♥");
      break;
    case SUIT_SPADE:desc.append("♠");
      break;
    case SUIT_DIAMOND:desc.append("♠");
      break;
    case MAX_SUITS:
    default:desc.append("WTF");
      break;
  }
  std::cout << desc << '\n';
}
int Card::getCardValue() const {
  int value{0};
  switch (m_rank) {
    case RANK_2:
    case RANK_3:
    case RANK_4:
    case RANK_5:
    case RANK_6:
    case RANK_7:
    case RANK_8:
    case RANK_9:value = static_cast<int>(m_rank) + 2;
      break;
    case RANK_10:
    case RANK_JACK:
    case RANK_QUEEN:
    case RANK_KING:value = 10;
      break;
    case RANK_ACE:value = 11;
      break;
    case MAX_RANKS:
    default:value = -1;
      break;
  }
  return value;
}
