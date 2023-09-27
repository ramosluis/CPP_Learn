#include <iostream>

void toBinary(int num)
{
	if (num == 0)
		return;

	toBinary(num / 2);

	std::cout << num % 2 << ' ';
}

int main()
{
	toBinary(148);

	return 0;
}