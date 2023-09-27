#include <iostream>
#include <string_view>
#include <iterator> // for std::size

int main()
{
	constexpr int divisors[]{ 3, 5, 7, 11, 13, 17, 19 };
	constexpr std::string_view words[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
	static_assert(std::size(divisors) == std::size(words));

	for (int i{ 1 }; i < 22; ++i)
	{
		int divisorsSize = static_cast<int>(std::size(divisors));
		bool matched{ false };
		for (int j{ 0 }; j < divisorsSize; ++j)
		{
			if (i % divisors[j] == 0)
			{
				std::cout << words[j];
				matched = true;
			}

		}

		if (!matched)
			std::cout << i;
		std::cout << '\n';
	}
}