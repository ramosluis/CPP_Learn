#include <iostream>
#include "Calculator.h"

int main()
{
	int a{ getNumber() };
	int b{ getNumber() };
	char operation{ getOperation() };
	ArithmeticFunction fcnPtr{ getArithmeticFunction(operation) };

	if (fcnPtr)
		std::cout << a << ' ' << operation << ' ' << b << " = " << fcnPtr(a, b) << '\n';

	return 0;
}