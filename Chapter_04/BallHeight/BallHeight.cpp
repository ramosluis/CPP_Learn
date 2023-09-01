#include <iostream>

double calculateHeight(double height, int seconds);
void printHeight(double height, int seconds);

int main()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;

	printHeight(calculateHeight(height, 0), 0);
	printHeight(calculateHeight(height, 1), 1);
	printHeight(calculateHeight(height, 2), 2);
	printHeight(calculateHeight(height, 3), 3);
	printHeight(calculateHeight(height, 4), 4);
	printHeight(calculateHeight(height, 5), 5);

	return 0;
}

double calculateHeight(double height, int seconds)
{
	constexpr double gravityConstant = 9.8;

	double fallDistance{ gravityConstant * (static_cast<double>(seconds) * static_cast<double>(seconds)) / 2.0 };
	return height - fallDistance;
}

void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << ", the ball is at height: " << height << " meters\n";
	else
		std::cout << "The ball is on the ground";
}