#include <iostream>
#include <array>
//#include <numeric> // for std::reduce() (C++17 onwards)

namespace Inventory
{
	enum
	{
		Health_Potions,
		Torches,
		Arrows,
		Max_Items,
	};
}

int countTotalItems(const std::array<int, Inventory::Max_Items>& inventory)
{
	// alternative
	// return std::reduce(inventory.begin(), inventory.end());
	return inventory[Inventory::Health_Potions] + inventory[Inventory::Torches] + inventory[Inventory::Arrows];
}

int main()
{
	std::array<int, Inventory::Max_Items> inventory{ 2, 5, 10 };

	std::cout << "There are " << countTotalItems(inventory) << " items in total.\n";
	std::cout << "Including " << inventory[Inventory::Torches] << " torches.\n";

	return 0;
}