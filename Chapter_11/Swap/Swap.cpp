#include <iostream>

void swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}

int main()
{
	std::cout << "Enter first number: ";
	int a{};
	std::cin >> a;

	std::cout << "Enter second number: ";
	int b{};
	std::cin >> b;

	std::cout << "Swapped: ";
	swap(a, b);
	std::cout << a << ' ' << b << '\n';

	return 0;
}