#include <iostream>
#include <gtest/gtest.h>
#include "LibraryCode.hpp"
#include <vector>

void PrintResults(int exp, int act)
{
    std::cout << "Expected: " << exp << "\n Actual: " << act << '\n';
}

TEST(TestCountPositives, All6Positives)
{
    //Arrange
    std::vector<int> inputVector{ 1,2,3,4,5,6 };
    //Act
    int count = countOfPositives(inputVector);
    //Assert    
    ASSERT_EQ(6,count);
}

TEST(TestCountPositives, NoNumbers)
{
    //Arrange
    std::vector<int> inputVector{};
    //Act
    int count = countOfPositives(inputVector);
    //Assert    
    ASSERT_EQ(0,count);
}

TEST(TestCountPositives, All6Negatives)
{
    //Arrange
    std::vector<int> inputVector{ -1,-2,-3,-4,-5,-6};
    //Act
    int count = countOfPositives(inputVector);
    //Assert    
    ASSERT_EQ(0,count);
}

int main (int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}