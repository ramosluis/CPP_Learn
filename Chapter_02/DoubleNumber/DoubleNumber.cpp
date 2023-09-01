#include <iostream>

int doubleNumber(int num)
{
	return num * 2;
}

int main()
{
	int inputNumber{};
	std::cout << "Enter a number: ";
	std::cin >> inputNumber;
	std::cout << "Double of " << inputNumber << " is: " << doubleNumber(inputNumber) << '\n';

	return 0;
}