#include <iostream>
#include "Cards.h"
#include "Blackjack.h"

int main()
{
	auto deck{ createDeck() };

	shuffleDeck(deck);

	if (playBlackJack(deck))
		std::cout << "You won!\n";
	else
		std::cout << "The house won!\n";

	return 0;
}