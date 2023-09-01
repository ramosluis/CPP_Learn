#include <iostream>

bool isEven(int num)
{
	return (num % 2) == 0;
}

int main()
{
	std::cout << "Enter an integer: ";
	int answer{};
	std::cin >> answer;

	if (isEven(answer))
		std::cout << answer << " is even.\n";
	else
		std::cout << answer << " is odd.\n";
}