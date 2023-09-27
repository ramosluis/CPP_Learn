#include <iostream>
#include <array>
#include <cassert>

class Stack
{
	std::array<int, 10> m_stack{};
	int m_size{};

public:
	void reset()
	{
		m_size = 0;
	}

	bool push(int value)
	{
		if (m_size >= m_stack.size())
			return false;

		m_stack.at(m_size++) = value;

		return true;
	}

	int pop()
	{
		assert(m_size > 0 && "Can't pop empty stack.");

		int poppedValue = m_stack.at(m_size - 1);

		--m_size;

		return poppedValue;
	}

	void print()
	{
		std::cout << "( ";

		for (int i{ 0 }; i < m_size; ++i)
		{
			std::cout << m_stack.at(i) << ' ';
		}

		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}