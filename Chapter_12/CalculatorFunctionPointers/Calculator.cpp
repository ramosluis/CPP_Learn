#include <iostream>
#include "Calculator.h"

int getNumber()
{
	std::cout << "Enter a number: ";
	int temp{};
	std::cin >> temp;

	return temp;
}

char getOperation()
{
	while (true)
	{
		std::cout << "Enter the operation you wish to perform (+, -, *, /): ";
		char operation{};
		std::cin >> operation;

		switch (operation)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return operation;
		default:
			std::cout << "Invalid operation.\n\n";
		}
	}
}

int add(int x, int y)
{
	return (x + y);
}

int subtract(int x, int y)
{
	return (x - y);
}

int multiply(int x, int y)
{
	return (x * y);
}

int divide(int x, int y)
{
	return (x / y);
}

ArithmeticFunction getArithmeticFunction(char operation)
{
	switch (operation)
	{
	case '+': return &add;
	case '-': return &subtract;
	case '*': return &multiply;
	case '/': return &divide;
	}

	return nullptr;
}