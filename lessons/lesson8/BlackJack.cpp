//
// Created by pdzhambazov on 13.07.18.
//

#include <iostream>
#include <random>
#include <ctime>
#include <cassert>
#include "BlackJack.h"

void printTurn(const std::string &player, const Card &card) {
  std::cout << player << ": ";
  card.printCard();
}
char getPlayerChoice() {
  std::cout << "(h) to hit, (s) to stand: ";

  char choice;
  do {
    std::cin >> choice;
  } while (choice != 'h' && choice != 's');
  return choice;
}

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

Deck::Deck() {
  const auto i = 52;
  const auto cardsInASuit = 13;
  for (int suit = 0; suit < Card::MAX_SUITS; ++suit) {
    for (int rank = 0; rank < Card::MAX_RANKS; ++rank) {
      int idx = (suit * cardsInASuit) + rank; // (0*13)+0|(1*13)+0
      m_deck[idx] = Card(static_cast<Card::CardRank >(rank), static_cast<Card::CardSuit >(suit));
    }
  }
}

void Deck::printDeck() const {
  for (auto c: m_deck) {
    c.printCard();
  }
  std::cout << '\n';
}
void Deck::shuffleDeck() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::random_device rd;
  std::mt19937_64 mersenne(rd());
  std::uniform_int_distribution<> randomCard(0, 51);
  m_cardIndex = 0;

  for (int i = 0; i < 52; ++i) {
    int shuffleIdx = randomCard(mersenne);
    swapCards(m_deck[i], m_deck[shuffleIdx]);
  }
}
void Deck::swapCards(Card &card1, Card &card2) {
  Card temp = card1;
  card1 = card2;
  card2 = temp;
}

const Card& Deck::dealCard(){
  assert(m_cardIndex < 52);
  return m_deck[m_cardIndex++];
}

BlackjackResult playBlackjack(Deck &deck) {
  int totalPlayer = 0,
      totalDealer = 0;

  const auto dealer = "Dealer";
  const auto player = "Player";

  auto &card = deck.dealCard();
  printTurn(dealer, card);
  totalDealer += card.getCardValue(); // dealer first card

  card = deck.dealCard();
  printTurn(player, card);
  totalPlayer += card.getCardValue(); // player first card
  printTurn(player, card);
  totalPlayer += card.getCardValue(); // player second card

  while (true) {
    std::cout << "Player total: " << totalPlayer << "\n";
    if (getPlayerChoice() == 's')
      break;
    // hit
    printTurn(player, card);
    auto cardValue = card.getCardValue();
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
    printTurn(dealer, card);
    totalDealer += card.getCardValue();
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
