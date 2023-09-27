#include <iostream>
#include <vector>
#include <random> // for std::mt19937 and random_device
#include <cmath> // for std::abs

namespace config
{
	constexpr int multiplierMin{ 2 };
	constexpr int multiplierMax{ 4 };
	constexpr int maxWrongAnswer{ 4 };
}

int getInteger();
std::vector<int> generateSquares(int start, int amount);
void printVector(std::vector<int> vector);
void playGame(std::vector<int>& squares);


int main()
{
	std::cout << "Start where? ";
	int start{ getInteger() };
	std::cout << "How many? ";
	int amount{ getInteger() };

	std::vector<int> squares{ generateSquares(start, amount) };
	playGame(squares);

	// printVector(squares);
}

int getInteger()
{
	int num{};
	std::cin >> num;
	return num;
}

std::vector<int> generateSquares(int start, int amount)
{
	std::vector<int> squares(amount);
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> randomGenerator{ config::multiplierMin, config::multiplierMax };

	int multiplier{ randomGenerator(mt) };

	for (int i{ 0 }; i < amount; ++i, ++start)
	{
		squares[i] = start * start * multiplier;
	}

	std::cout << "I generated " << amount << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";

	return squares;
}

void printVector(std::vector<int> vector)
{
	for (auto& element : vector)
		std::cout << element << ' ';
	std::cout << '\n';
}

void playGame(std::vector<int>& squares)
{
	int guess{};
	while (true)
	{
		if (squares.size() == 0)
		{
			std::cout << "Nice! You found all numbers, good job!\n";
			break;
		}

		std::cout << "> ";
		std::cin >> guess;

		auto found{ std::find(squares.begin(), squares.end(), guess) };

		if (found == squares.end())
		{
			const auto closest{ std::min_element(squares.begin(), squares.end(),
								[=](const auto& a, const auto& b) {
									return (std::abs(a - guess) < std::abs(b - guess));
								}) };

			std::cout << guess << " is wrong!";
			
			if (std::abs(*closest - guess) <= config::maxWrongAnswer)
				std::cout << " Try " << *closest << " next time.\n";
			else
				std::cout << '\n';
			break;
		}
		else
		{
			squares.erase(found);
			if (squares.size() > 0)
				std::cout << "Nice! " << squares.size() << " number(s) left.\n";
		}
	}
}