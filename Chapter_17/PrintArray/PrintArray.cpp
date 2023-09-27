#include <iostream>
#include <array>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
	bool first{ true };
	std::cout << "The array (";
	for (auto element : arr)
	{
		if (first)
		{
			first = false;
			std::cout << element;
		}
		else
			std::cout << ", " << element;
	}
	std::cout << ") has length " << arr.size() << '\n';
}

int main()
{
	constexpr std::array<int, 4> arr1{ 1, 4, 9, 16 };
	printArray(arr1);

	constexpr std::array<char, 5> arr2{ 'h', 'e', 'l', 'l', 'o' };
	printArray(arr2);

	return 0;
}