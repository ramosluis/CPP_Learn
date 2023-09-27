#include <iostream>
#include <iterator> // for std::size
#include <utility> // for std::swap

void printArray(const int array[], const int size)
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int array[]{ 30, 50, 20, 10, 40, 100, 60, 80, 90, 70 };
	constexpr int length = static_cast<int>(std::size(array));

	std::cout << "Array before sorting: \n";
	printArray(array, length);

	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int smallestIndex{ startIndex };
		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[smallestIndex]);
	}

	std::cout << "\n\nArray after sorting: \n";
	printArray(array, length);
}