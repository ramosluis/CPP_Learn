#include <iostream>

double doubleInput()
{
	std::cout << "Enter a double value: ";
	double num{};
	std::cin >> num;

	return num;
}

char operationInput()
{
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char operation{};
	std::cin >> operation;

	return operation;
}

void printAnswer(double num1, double num2, char operation)
{
	if (operation == '+')
	{
		std::cout << num1 << " " << operation << " " << num2 << " is " << num1 + num2 << '\n';
	}
	else if (operation == '-')
	{
		std::cout << num1 << " " << operation << " " << num2 << " is " << num1 - num2 << '\n';
	}
	else if (operation == '*')
	{
		std::cout << num1 << " " << operation << " " << num2 << " is " << num1 * num2 << '\n';
	}
	else if (operation == '/')
	{
		std::cout << num1 << " " << operation << " " << num2 << " is " << num1 / num2 << '\n';
	}
}

int main()
{
	double num1{ doubleInput() };
	double num2{ doubleInput() };
	char operation{ operationInput() };

	printAnswer(num1, num2, operation);

	return 0;
}