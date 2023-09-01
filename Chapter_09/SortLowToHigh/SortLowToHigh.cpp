#include <iostream>

void sort2(int& lesser, int& greater)
{
    if (lesser <= greater) return;

    int temp{ lesser };
    lesser = greater;
    greater = temp;
}

int main()
{
    int x{ 7 };
    int y{ 5 };

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y);
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}