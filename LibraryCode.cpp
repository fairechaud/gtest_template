#include "LibraryCode.hpp"
#include <vector>
#include <algorithm>

bool isThisPositive(int x)
{
    return x >= 0;
}

int countOfPositives(std::vector<int> const& inputVector)
{
    return std::count_if(inputVector.begin(), inputVector.end(), isThisPositive);
}


