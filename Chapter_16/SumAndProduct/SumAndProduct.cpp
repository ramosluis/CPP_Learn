#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers(3);

	std::cout << "Enter 3 integers: ";

	std::cin >> numbers[0] >> numbers[1] >> numbers[2];

	std::cout << "The sum is: " << numbers[0] + numbers[1] + numbers[2] << '\n';
	std::cout << "The product is: " << numbers[0] * numbers[1] * numbers[2] << '\n';

	return 0;
}