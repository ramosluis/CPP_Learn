#ifndef CARDS_H
#define CARDS_H

#include <array>

enum class CardRank
{
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
	Max_Ranks,
};


enum class CardSuit
{
	Clubs,
	Diamonds,
	Hearts,
	Spades,
	Max_Suits,
};

struct Card
{
	CardRank rank{};
	CardSuit suit{};
};

using Deck = std::array<Card, 52>;

void printCard(const Card& card);
Deck createDeck();
void printDeck(const Deck& deck);
void shuffleDeck(Deck& deck);
int getCardValue(const Card& card);

#endif