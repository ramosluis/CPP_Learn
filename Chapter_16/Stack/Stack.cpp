#include <iostream>
#include <vector>

void printStackValues(const std::vector<int>& stack)
{
	std::cout << "\t(Stack:";

	for (auto element : stack)
		std::cout << ' ' << element;

	if (stack.size() == 0)
		std::cout << "Empty";

	std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& stack, int value)
{
	stack.emplace_back(value);
	std::cout << "Push " << value;
	printStackValues(stack);
}

void popAndPrint(std::vector<int>& stack)
{
	stack.pop_back();
	std::cout << "Pop ";
	printStackValues(stack);
}

int main()
{
	std::vector<int> stack{};
	
	printStackValues(stack);

	pushAndPrint(stack, 1);
	pushAndPrint(stack, 2);
	pushAndPrint(stack, 3);
	popAndPrint(stack);
	pushAndPrint(stack, 4);
	popAndPrint(stack);
	popAndPrint(stack);
	popAndPrint(stack);

	return 0;
}