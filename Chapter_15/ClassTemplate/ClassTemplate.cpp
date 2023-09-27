#include <iostream>

template <typename T, typename U, typename V>
class Triad
{
private:
	T m_first{};
	U m_second{};
	V m_third{};

public:
	Triad(T first, U second, V third)
		: m_first{ first }, m_second{ second }, m_third{ third }
	{
	}

	void print()
	{
		std::cout << '[' << m_first << ", " << m_second << ", " << m_third << "]";
	}
};

int main()
{
	Triad t1{ 1, 2, 3 };
	t1.print();

	Triad t2{ 1, 2.3, "Hello" };
	t2.print();

	return 0;
}