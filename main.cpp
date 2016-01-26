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
    else if (n == 4)
    {
        str += "IV";
    }
    else if (n > 4 && n < 9)
    {
        str += "V";
        for (int i = 5; i < n; i++)
        {
            str += 'I';
        }
    }
    else if (n == 9)
    {
        str += "IX";
    }
    else if (n > 9 && n < 14)
    {
        str += "X";
        for (int i = 10; i < n; i++)
        {
            str += "I";
        }
    }
    else if (n == 14)
    {
        str += "XIV";
    }
    else if (n > 14)
    {
        str += "XV";
        for (int i = 15; i < n; i++)
        {
            str += "I";
        }    }
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



