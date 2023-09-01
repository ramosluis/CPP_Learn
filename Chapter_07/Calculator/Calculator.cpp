#include <iostream>

int calculate(int x, int y, char operation)
{
	switch (operation)
	{
		case '+':
			std::cout << x << " + " << y << " = " << x + y << '\n';
			break;
		case '-':
			std::cout << x << " - " << y << " = " << x - y << '\n';
			break;
		case '*':
			std::cout << x << " * " << y << " = " << x * y << '\n';
			break;
		case '/':
			std::cout << x << " / " << y << " = " << x / y << '\n';
			break;
		case '%':
			std::cout << x << " % " << y << " = " << x % y << '\n';
			break;
		default:
			std::cout << "Invalid operation.";
			break;
	}

	return 0;
}

int main()
{
	calculate(5, 10, '+');
	calculate(5, 10, '-');
	calculate(5, 10, '*');
	calculate(20, 10, '/');
	calculate(5, 2, '%');
}