#include <iostream>

int sumDigits(int number)
{
	if (number < 10)
		return number;

	return sumDigits(number / 10) + (number % 10);
}

int main()
{
	std::cout << sumDigits(93427) << '\n';

	return 0;
}