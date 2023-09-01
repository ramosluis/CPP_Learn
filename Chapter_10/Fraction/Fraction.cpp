#include <iostream>

struct Fraction
{
	int numerator{};
	int denominator{ 1 };
};

Fraction enterFraction()
{
	Fraction fraction{};
	std::cout << "Enter a value for the numerator: ";
	std::cin >> fraction.numerator;

	std::cout << '\n';

	std::cout << "Enter a value for the denominator: ";
	std::cin >> fraction.denominator;

	std::cout << '\n';

	return fraction;
}

Fraction multiplyFractions(const Fraction& f1, const Fraction& f2)
{
	return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

void printFraction(const Fraction& fraction)
{
	std::cout << fraction.numerator << '/' << fraction.denominator << '\n';
}

int main()
{
	Fraction firstFraction{ enterFraction() };
	Fraction secondFraction{ enterFraction() };

	std::cout << "Your fractions multiplied together: ";
	printFraction(multiplyFractions(firstFraction, secondFraction));

	return 0;
}