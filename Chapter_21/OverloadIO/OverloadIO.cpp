#include <iostream>
#include <numeric> // for std::gcd
#include <cmath> // for std::abs
#include <limits> // for std::numeric_limits

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

	int gcd(int a, int b) {
		return (b == 0) ? std::abs(a) : gcd(b, a % b);
	}

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator } {}

	void print()
	{
		int divisor{ gcd(m_numerator, m_denominator) };
		std::cout << m_numerator / divisor << '/' << m_denominator / divisor << '\n';
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
	friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);
	friend std::istream& operator>> (std::istream& in, Fraction& fraction);
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction{ f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
	return f1 * value;
}

std::ostream& operator<< (std::ostream& out, const Fraction& fraction)
{
	out << fraction.m_numerator << '/' << fraction.m_denominator;
	return out;
}

std::istream& operator>> (std::istream& in, Fraction& fraction)
{
	char ignore{};
	in >> fraction.m_numerator >> ignore >> fraction.m_denominator;
	in.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
	return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}