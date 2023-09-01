#include <iostream>

int main()
{
	std::cout << "Enter a number between 0-255: ";
	int decimal{};
	std::cin >> decimal;

	std::cout << decimal << " in binary is: ";

	int binary{ 0 };
	int power{ 1 };
	while (decimal > 0) 
	{
		binary += (decimal % 2) * power;
		decimal /= 2;
		power *= 10;
	}

	std::cout << binary << '\n';
	return 0;
}