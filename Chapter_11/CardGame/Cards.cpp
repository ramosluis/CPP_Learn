#include "Cards.h"
#include <iostream>
#include <algorithm> // std::shuffle
#include <chrono>
#include <random>

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case CardRank::Two: std::cout << '2';	break;
	case CardRank::Three: std::cout << '3';	break;
	case CardRank::Four: std::cout << '4';	break;
	case CardRank::Five: std::cout << '5';	break;
	case CardRank::Six: std::cout << '6';	break;
	case CardRank::Seven: std::cout << '7';	break;
	case CardRank::Eight: std::cout << '8';	break;
	case CardRank::Nine: std::cout << '9';	break;
	case CardRank::Ten: std::cout << 'T';	break;
	case CardRank::Jack: std::cout << 'J';	break;
	case CardRank::Queen: std::cout << 'Q';	break;
	case CardRank::King: std::cout << 'K';	break;
	case CardRank::Ace: std::cout << 'A';	break;
	default: std::cout << '?';	break;
	}

	switch (card.suit)
	{
	case CardSuit::Clubs: std::cout << 'C';	break;
	case CardSuit::Diamonds: std::cout << 'D';	break;
	case CardSuit::Hearts: std::cout << 'H';	break;
	case CardSuit::Spades: std::cout << 'S';	break;
	default: std::cout << '?';	break;
	}
}

Deck createDeck()
{
	Deck deck{};
	int card{};

	for (int suit{ 0 }; suit < static_cast<int>(CardSuit::Max_Suits); ++suit)
	{
		for (int rank{ 0 }; rank < static_cast<int>(CardRank::Max_Ranks); ++rank)
		{
			deck[card].rank = static_cast<CardRank>(rank);
			deck[card].suit = static_cast<CardSuit>(suit);
			++card;
		}
	}
	return deck;
}

void printDeck(const Deck& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << "\n\n";
}

void shuffleDeck(Deck& deck)
{
	static std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case CardRank::Two: return 2;
	case CardRank::Three: return 3;
	case CardRank::Four: return 4;
	case CardRank::Five: return 5;
	case CardRank::Six: return 6;
	case CardRank::Seven: return 7;
	case CardRank::Eight: return 8;
	case CardRank::Nine: return 9;
	case CardRank::Ten:
	case CardRank::Jack:
	case CardRank::Queen:
	case CardRank::King:
		return 10;
	case CardRank::Ace: return 11;
	default: return 0;
	}
}