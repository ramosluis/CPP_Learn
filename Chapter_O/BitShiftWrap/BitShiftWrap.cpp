#include <bitset>
#include <iostream>

// rotl stands for rotate left
std::bitset<4> rotl(std::bitset<4> bits)
{
	constexpr std::bitset<4> mask{ 0b1000 };
	const std::bitset<4> shifted{ bits & mask };

	if (shifted == mask)
	{
		bits <<= 1;
		bits |= 1;
	}
	else
		bits <<= 1;

	return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}