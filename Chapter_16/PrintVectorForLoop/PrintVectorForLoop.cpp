#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits

template <typename T>
void printArray(const std::vector<T>& arr)
{
	std::size_t length{ arr.size() };

	for (std::size_t index{ 0 }; index < length; ++index)
	{
		std::cout << arr[index] << ' ';
	}
	std::cout << '\n';
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNumber()
{
	while (true)
	{
		std::cout << "Enter a number between 1 and 9: ";
		int userInput{};
		std::cin >> userInput;

		if (!std::cin || userInput < 1 || userInput > 9)
		{
			std::cin.clear();
			ignoreLine();
		}
		else
		{
			ignoreLine();
			return userInput;
		}
	}
}

template <typename T>
int searchArray(const std::vector<T>& arr, int value)
{
	std::size_t length{ arr.size() };
	for (std::size_t index{ 0 }; index < length; ++index)
	{
		if (arr[index] == value)
		{
			return index;
		}
	}

	return -1;
}

int main()
{
	std::vector<int> numbers{ 4, 6, 7, 3, 8, 2, 1, 9 };
	int value{ getNumber() };
	printArray(numbers);
	int index{ searchArray(numbers, value) };

	if (index != -1)
		std::cout << "The number " << value << " has index " << static_cast<int>(index) << '\n';
	else
		std::cout << "The number " << value << " is not in the provided array\n";
	return 0;
}