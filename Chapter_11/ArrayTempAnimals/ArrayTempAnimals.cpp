#include <iostream>

namespace Animals
{
	enum Animals // the name of this enum could be omitted since it's not used anywhere
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		numberOfAnimals,
	};
}

int main()
{
	double temperature[365]{};
	int legs[Animals::numberOfAnimals]{ 2, 4, 4, 4, 2, 0 };

	std::cout << "An elephant has " << legs[Animals::elephant] << " legs\n";

	return 0;
}