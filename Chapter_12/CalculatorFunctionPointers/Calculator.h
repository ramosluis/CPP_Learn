#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getNumber();
char getOperation();
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
ArithmeticFunction getArithmeticFunction(char operation);

#endif