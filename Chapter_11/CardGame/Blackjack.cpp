#include <vector>
#include <iostream>
#include "Cards.h"
#include "Blackjack.h"

namespace GameValues
{
	int cardInDeck{};
	constexpr int maxValue{ 21 };
	constexpr int dealerMaxValue{ 17 };
}

bool playBlackJack(const Deck& deck)
{
	Hand dealerHand{ deck[GameValues::cardInDeck] };
	Hand playerHand{ deck[++GameValues::cardInDeck], deck[++GameValues::cardInDeck] };

	if (getHandValue(playerHand) == GameValues::maxValue)
	{
		std::cout << "Cards: ";
		printHand(playerHand);
		std::cout << "Blackjack!\n";
		return true;
	}

	if (playerTurn(playerHand, deck))
	{
		std::cout << '\n';
		// if the player didn't bust, then it's the dealer's turn
		if (!(dealerTurn(dealerHand, deck)))
			return true; // if dealer busts, player wins

		if (getHandValue(playerHand) > getHandValue(dealerHand))
			return true; // if player had the better hand, player wins
	}

	std::cout << "\n\n";
	std::cout << "Player's hand total value: " << getHandValue(playerHand) << '\n';
	std::cout << "Dealer's hand total value: " << getHandValue(dealerHand) << '\n';

	return false; // if dealer had the better hand, or the player busts, or hand values are tied, player loses
}

bool playerTurn(Hand& hand, const Deck& deck)
{
	while (true)
	{
		std::cout << "Cards: ";
		printHand(hand);
		std::cout << "Hand total value: " << getHandValue(hand) << '\n';
		std::cout << "What would you like to do? (h = hit, s = stand): ";
		char action{};
		std::cin >> action;

		if (action == 's')
			return true;
		else if (action == 'h')
		{
			hand.resize(hand.size() + 1);
			hand.at(hand.size() - 1) = deck[++GameValues::cardInDeck];
		}
		else
			std::cout << "Invalid command.\n\n";

		if (getHandValue(hand) > GameValues::maxValue)
		{
			std::cout << "Cards: ";
			printHand(hand);
			std::cout << "Hand total value: " << getHandValue(hand) << '\n';
			std::cout << "Bust!\n";
			return false;
		}
		else if (getHandValue(hand) == GameValues::maxValue)
			return true;
	}
}

bool dealerTurn(Hand& hand, const Deck& deck)
{
	do
	{
		std::cout << "Dealer's Cards: ";
		printHand(hand);
		std::cout << "Dealer's hand total value: " << getHandValue(hand) << '\n';
		hand.resize(hand.size() + 1);
		hand.at(hand.size() - 1) = deck[++GameValues::cardInDeck];
	} while (getHandValue(hand) < GameValues::dealerMaxValue);

	if (getHandValue(hand) > GameValues::maxValue)
	{
		std::cout << "Dealer's Cards: ";
		printHand(hand);
		std::cout << "Dealer's hand total value: " << getHandValue(hand) << '\n';
		std::cout << "Dealer bust!\n";
		return false;
	}

	std::cout << "Dealer's Cards: ";
	printHand(hand);
	std::cout << "Dealer's hand total value: " << getHandValue(hand) << '\n';

	return true;
}

int getHandValue(Hand& hand)
{
	int sum{};
	for (Card card : hand)
	{
		sum += getCardValue(card);
	}

	return sum;
}

void printHand(Hand& hand)
{
	for (Card card : hand)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}