#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include "Cards.h"

using Hand = std::vector<Card>;

bool playBlackJack(const Deck& deck);
bool playerTurn(Hand& playerHand, const Deck& deck);
bool dealerTurn(Hand& playerHand, const Deck& deck);
int getHandValue(Hand& playerHand);
void printHand(Hand& hand);

#endif