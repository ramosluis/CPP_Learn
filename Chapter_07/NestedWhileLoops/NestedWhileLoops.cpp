#include <iostream>

int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		int inner{ outer };
		while (inner >= 1)
		{
			std::cout << inner-- << ' ';
		}

		std::cout << '\n';
		--outer;
	}

	std::cout << "\n\n\n";

	outer =  1;
	while (outer <= 5)
	{
		int inner{ 5 };
		while (inner >= 1)
		{
			if (outer < inner)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << inner << ' ';
			}
			
			--inner;
		}

		std::cout << '\n';
		++outer;
	}

	return 0;
}