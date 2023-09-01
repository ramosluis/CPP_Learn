#include <iostream>
#include <limits>
#include "Random.h"

int getGuess(int count)
{
	while (true) // loop until user enters valid input
	{
		std::cout << "Guess #" << count << ": ";

		int guess{};
		std::cin >> guess;

		if (std::cin.fail()) // did the extraction fail?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input
			continue; // and try again
		}

		// If the guess was out of bounds
		if (guess < 1 || guess > 100)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove the bad input
			continue; // and try again
		}

		// We may have gotten a partial extraction (e.g. user entered '43x')
		// We'll remove any extraneous input before we proceed
		// so the next extraction doesn't fail
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return guess;
	}
}

// returns true if the user won, false if they lost
bool playGame(int guesses, int number)
{
	// Loop through all of the guesses
	for (int count{ 1 }; count <= guesses; ++count)
	{
		int guess{ getGuess(count) };

		if (guess > number)
			std::cout << "Your guess is too high.\n";
		else if (guess < number)
			std::cout << "Your guess is too low.\n";
		else // guess == number
			return true;
	}
	return false;
}

bool playAgain()
{
	// Keep asking the user if they want to play again until they pick y or n.
	while (true)
	{
		char ch{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;

		switch (ch)
		{
		case 'y':
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return true;
		case 'n':
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return false;
		default:
			// clear out any extraneous input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

int main()
{
	constexpr int guesses{ 7 }; // the user has this many guesses

	do
	{
		int number{ Random::get(1,100) }; // this is the number the user needs to guess
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << guesses << " tries to guess what it is.\n";
		bool won{ playGame(guesses, number) };
		if (won)
			std::cout << "Correct! You win!\n";
		else
			std::cout << "Sorry, you lose. The correct number was " << number << '\n';
	} while (playAgain());

	std::cout << "Thank you for playing.\n";
	return 0;
}