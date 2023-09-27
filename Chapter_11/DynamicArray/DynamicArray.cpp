#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
	std::cout << "How many names would you like to enter? ";
	std::size_t count{};
	std::cin >> count;

	std::string* array{ new std::string[count] };

	for (int i{ 0 }; i < count; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::getline(std::cin >> std::ws, array[i]);
	}

	std::sort(array, (array + count));

	for (int i{ 0 }; i < count; ++i)
	{
		std::cout << "Name #" << i + 1 << ": " << array[i] << '\n';
	}

	delete[] array;

	return 0;
}