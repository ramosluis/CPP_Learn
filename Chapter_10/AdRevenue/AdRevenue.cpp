#include <iostream>

struct Advertisement
{
	int watched{};
	double percentageClicked{};
	double averageEarnings{};
};

void printAdvertisementStats(const Advertisement& ad)
{
	std::cout << "This ad was watched " << ad.watched << " times.\n";
	std::cout << ad.percentageClicked << "% of users clicked on it.\n";
	std::cout << "The average earnings per click of this ad were $" << ad.averageEarnings << '\n';
	std::cout << "In total, $" << (ad.watched * (ad.percentageClicked / 100) * ad.averageEarnings) << " was made for today.\n";
}

int main()
{
	Advertisement ad{ 100, 10.3, 12.75 };
	printAdvertisementStats(ad);

	return 0;
}