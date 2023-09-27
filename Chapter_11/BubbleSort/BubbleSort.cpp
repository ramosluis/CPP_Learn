#include <iostream>
#include <iterator> // for std::size
#include <utility> // for std::swap

void printArray(const int array[], const int length);

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	std::cout << "Array before:\n";
	printArray(array, length);

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i{ 0 }; i < length - 1; ++i)
		{
			if (array[i + 1] < array[i])
			{
				std::swap(array[i + 1], array[i]);
				sorted = false;
			}
		}
	}

	std::cout << "Array after:\n";
	printArray(array, length);
	return 0;
}

void printArray(const int array[], const int length)
{
	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << "\n\n\n";
}