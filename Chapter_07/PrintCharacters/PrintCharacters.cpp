#include <iostream>

int main()
{
	char charToPrint{ 'a' };

	while (charToPrint <= 'z')
	{
		std::cout << charToPrint << " has ASCII code " << static_cast<int>(charToPrint) << '\n';
		++charToPrint;
	}

	return 0;
}