#include <iostream>

int factorial(int num)
{
	if (num < 1)
		return 1;

	return factorial(num - 1) * num;
}

int main()
{
	for (int i{ 0 }; i < 8; ++i)
		std::cout << factorial(i) << '\n';

	return 0;
}