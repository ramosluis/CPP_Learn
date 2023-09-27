#include <iostream>
#include <vector>

int findMax(const std::vector<int>& arr)
{
    int max{ arr[0] };
    std::size_t length{ arr.size() };

    for (std::size_t index{ 1 }; index < length; ++index)
    {
        if (arr[index] > max)
            max = arr[index];
    }

    return max;
}

int main()
{
    std::vector<int> testScore{ 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

    return 0;
}