#include <iostream>
#include <vector>
#include <string>
#include <string_view>

int main()
{
	using namespace std::literals::string_view_literals;
	const std::vector<std::string_view> names{ "Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv };

	std::cout << "Enter a name: ";
	std::string input{};
	std::cin >> input;
	bool found{ false };

	for (const std::string_view& name : names)
	{
		if (name == input)
		{
			std::cout << name << " was found.\n";
			found = true;
			break;
		}
	}

	if (!found)
		std::cout << input << " was not found.\n";

	return 0;
}