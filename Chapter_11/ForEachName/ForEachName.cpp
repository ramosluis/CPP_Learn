#include <iostream>
#include <string_view>
#include <string>

int main()
{
	constexpr std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string input{};
	std::cin >> input;

	bool found{ false };

	for (std::string_view name : names)
	{
		if (name == input)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		std::cout << input << " was found.\n";
	}
	else
	{
		std::cout << input << " was not found.\n";
	}
}