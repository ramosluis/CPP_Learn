#include <iostream>

int main()
{
	std::cout << "Enter a single character: ";
	char answer{};
	std::cin >> answer;

	std::cout << "You entered '" << answer << "', which has ASCII code " << static_cast<int>(answer) << ".\n";

	return 0;
}