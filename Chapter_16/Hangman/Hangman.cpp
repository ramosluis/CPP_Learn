#include <iostream>
#include <vector>
#include <string_view>
#include <limits>
#include "Random.h"

namespace Settings
{
	constexpr int wrongGuessesAllowed{ 6 };
}

namespace WordList
{
	using namespace std::literals;
	std::vector<std::string_view> words{ "mystery"sv, "broccoli"sv, "account"sv, "almost"sv,
		"spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv };

	std::string_view getRandomWord()
	{
		return words[Random::get(0, words.size() - 1)];
	}
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Session
{
private:
	std::string_view m_word{};
	int m_wrongGuessesLeft{};
	std::vector<bool> m_guessedLetter{ std::vector<bool>(26) };

	std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }

public:
	Session() : m_word{ WordList::getRandomWord() }, m_wrongGuessesLeft{ Settings::wrongGuessesAllowed }
	{
	}

	std::string_view getWord() const { return m_word; }

	int wrongGuessesLeft() const { return m_wrongGuessesLeft; }
	void removeGuess() { --m_wrongGuessesLeft; }

	bool isLetterGuessed(char c) const { return m_guessedLetter[toIndex(c)]; }
	void setGuessedLetter(char c) { m_guessedLetter[toIndex(c)] = true; }

	bool isLetterInWord(char c) const
	{
		for (auto ch : m_word) // step through each character of word
		{
			if (ch == c)
				return true;
		}

		return false;
	}

	bool won()
	{
		for (auto c : m_word) // step through each letter of word
		{
			if (!isLetterGuessed(c))
				return false;
		}

		return true;
	}
};

void draw(const Session& s)
{
	std::cout << '\n';
	std::cout << "The word: ";

	for (auto& c : s.getWord()) // step through each letter in the word
	{
		if (s.isLetterGuessed(c))
			std::cout << c;
		else
			std::cout << '_';
	}

	std::cout << "   Wrong guesses: ";
	for (int i{ 0 }; i < s.wrongGuessesLeft(); ++i)
		std::cout << '+';

	for (char c{ 'a' }; c <= 'z'; ++c)
		if (s.isLetterGuessed(c) && !s.isLetterInWord(c))
			std::cout << c;

	std::cout << '\n';
}

char getGuess(const Session& s)
{
	while (true)
	{
		std::cout << "Enter your next letter: ";
		char c{};
		std::cin >> c;

		// handle bad input
		if (!std::cin)
		{
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again.\n";
			ignoreLine();
			continue;
		}

		// flush input buffer of extra whitespace or characters
		ignoreLine();

		// if the user entered an invalid char, try again
		if (c < 'a' || c > 'z')
		{
			std::cout << "That wasn't a valid input. Try again\n";
			continue;
		}

		// if the letter was already guessed, try again
		if (s.isLetterGuessed(c))
		{
			std::cout << "You already guessed that. Try again.\n";
			continue;
		}

		// getting here means it's a valid guess
		return c;
	}
}

void handleGuess(Session& s, char c)
{
	s.setGuessedLetter(c);

	if (s.isLetterInWord(c))
	{
		std::cout << "Yes, '" << c << "' is in the word!\n";
		return;
	}

	std::cout << "No, '" << c << "' is not in the word!\n";
	s.removeGuess();
}

int main()
{
	std::cout << "Welcome to C++man (a variant of Hangman)\n";
	std::cout << "To win: guess the word. To lose: run out of pluses.\n";

	Session s{};
	
	while (s.wrongGuessesLeft() && !s.won())
	{
		draw(s);
		char c{ getGuess(s) };
		handleGuess(s, c);
	}

	draw(s);

	if (!s.wrongGuessesLeft())
		std::cout << "You lost! The word was: " << s.getWord() << '\n';
	else
		std::cout << "You won!\n";

	return 0;
}