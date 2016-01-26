//
//  main.cpp
//  Tests
//  Author: Ben Kohl
//  Date: 1/26/16
//

#include <gtest/gtest.h>
#include <iostream>

std::string arabicToRoman(int n)
{
    std::string str = "";
    
    if (n < 4)
    {
        for (int i = 0; i < n; i++)
        {
            str += 'I';
        }
    }
    else
    {
        str += "IV";
    }
    
    return str;
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(aToR, testWithOne)
{
    EXPECT_EQ("I", arabicToRoman(1));
}

TEST(aToR, testWithTwo)
{
    EXPECT_EQ("II", arabicToRoman(2));
}

TEST(aToR, testWithFour)
{
    EXPECT_EQ("IV", arabicToRoman(4));
}