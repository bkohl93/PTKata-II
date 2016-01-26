//
//  main.cpp
//  Tests
//  Author: Ben Kohl
//  Date: 1/26/16
//

#include <gtest/gtest.h>
#include <iostream>

//take a valid arabic integer as input and returns its roman numeral representation
std::string arabicToRoman(int n)
{
    std::string str = "";
    int index = 0;
    
    std::string roman [10] = {"CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arabic [10] = {400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    while (n > 0)
    {
        if (n < arabic[index]) //if n is less than the given number, try the next smallest number
        {
            index++;
        }
        else
        {
            str += roman[index]; //otherwise, concatenate the string and reduce n by the number
            n -= arabic[index];
        }
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

TEST(aToR, testWithFive)
{
    EXPECT_EQ("V", arabicToRoman(5));
}

TEST(aToR, testWithSix)
{
    EXPECT_EQ("VI", arabicToRoman(6));
}

TEST(aToR, testWithNine)
{
    EXPECT_EQ("IX", arabicToRoman(9));
}

TEST(aToR, testWithTen)
{
    EXPECT_EQ("X", arabicToRoman(10));
}

TEST(aToR, testWithEleven)
{
    EXPECT_EQ("XI", arabicToRoman(11));
}

TEST(aToR, testWithFourteen)
{
    EXPECT_EQ("XIV", arabicToRoman(14));
}

TEST(aToR, testWithFifteen)
{
    EXPECT_EQ("XV", arabicToRoman(15));
}

TEST(aToR, testWithSixteen)
{
    EXPECT_EQ("XVI", arabicToRoman(16));
}

TEST(aToR, testWithNineteen)
{
    EXPECT_EQ("XIX", arabicToRoman(19));
}

TEST(aToR, testWithTwenty)
{
    EXPECT_EQ("XX", arabicToRoman(20));
}

TEST(aToR, testWithForty)
{
    EXPECT_EQ("XL", arabicToRoman(40));
}

TEST(aToR, testWithFifty)
{
    EXPECT_EQ("L", arabicToRoman(50));
}

TEST(aToR, testWithNinety)
{
    EXPECT_EQ("XC", arabicToRoman(90));
}

TEST(aToR, testWithOneHundred)
{
    EXPECT_EQ("C", arabicToRoman(100));
}

TEST(aToR, testWithFourHundred)
{
    EXPECT_EQ("CD", arabicToRoman(400));
}
