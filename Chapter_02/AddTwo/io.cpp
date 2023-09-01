#include <iostream>
#include "io.h"

int readNumber()
{
	std::cout << "Enter a number: ";
	int num{};
	std::cin >> num;
	return num;
}

void writeAnswer(int answer)
{
	std::cout << "The sum of both numbers is " << answer << '\n';
}