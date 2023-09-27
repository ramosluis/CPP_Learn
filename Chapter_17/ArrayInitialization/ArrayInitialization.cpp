#include <iostream>
#include <array>
#include <string_view>

struct Item
{
	std::string_view name{};
	int gold{};
};

template <std::size_t N>
void printItems(const std::array<Item, N>& items)
{
	for (const auto& item : items)
	{
		std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
	}
}

int main()
{
	using namespace std::literals;
	constexpr std::array<Item, 4> items{{
		{ "sword"sv, 5 },
		{ "dagger"sv, 3 },
		{ "club"sv, 2 },
		{ "spear"sv, 7 }
		}};
	printItems(items);

	return 0;
}