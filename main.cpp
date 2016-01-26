//
//  main.cpp
//  Tests
//  Author: Ben Kohl
//  Date: 1/26/16
//

#include <gtest/gtest.h>
#include <iostream>

//takes a valid arabic integer as input and returns its roman numeral representation
std::string arabicToRoman(int n)
{
    std::string str = "";
    int index = 0;
    
    std::string roman [13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arabic [13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

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

//takes a valid roman numeral as input and returns its arabic integer representation
int romanToArabic(std::string s)
{
    int num = 0, len = s.length();
    std::vector<int> numbers(len);
    
    for (int i = 0; i < len; i++) //put the integer corresponding to the individual numeral in an array
    {
        switch (s[i])
        {
            case 'I' :
                numbers[i] = 1;
                break;
                
            case 'V' :
                numbers[i] = 5;
                break;
                
            case 'X' :
                numbers[i] = 10;
                break;
                
            case 'L' :
                numbers[i] = 50;
                break;
                
            case 'C' :
                numbers[i] = 100;
                break;
                
            case 'D' :
                numbers[i] = 500;
                break;
                
            default :
                numbers[i] = 1000;
        }
    }
    
    for (int i = 0; i < len-1; i++) //if a smaller integer precedes a larger one, subtract, otherwise add
    {
        (numbers[i] < numbers[i+1]) ? num -= numbers[i] : num += numbers[i];
    }
    
    num += numbers[len-1]; //always add the last (possibly only) number in the array
    
    return num;
}

//takes a string and returns true if the string is a valid arabic integer representation of a roman numeral
bool validateNumber(std::string str)
{
    bool isANumber = true;
    int len = str.length();
    
    if (len < 5 && str[0] != '0') //make sure the number is not too large for atoi, nor has a leading zero
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                isANumber = false;
            }
        }
        
        if (isANumber)
        {
            int n = atoi(str.c_str());
            
            if (n > 3999 || n < 1) //valid roman numerals are only between 1 and 3999 inclusive
            {
                isANumber = false;
            }
        }
    }
    else
    {
        isANumber = false;
    }

    return isANumber;
}

//takes a string and returns true if the string is a valid roman numeral representation of an arabic integer
bool validateString(std::string str)
{
    bool isAString = true;
    int len = str.length();
    
    for (int i = 0; i < len; i++)
    {
        if (str[i] != 'I' && str[i] != 'V')
        {
            isAString = false;
        }
    }
    
    
    return isAString;
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

TEST(aToR, testWithFiveHundred)
{
    EXPECT_EQ("D", arabicToRoman(500));
}

TEST(aToR, testWithNineHundred)
{
    EXPECT_EQ("CM", arabicToRoman(900));
}

TEST(aToR, testWithOneThousand)
{
    EXPECT_EQ("M", arabicToRoman(1000));
}

TEST(rToA, testWithOne)
{
    EXPECT_EQ(1, romanToArabic("I"));
}

TEST(rToA, testWithTwo)
{
    EXPECT_EQ(2, romanToArabic("II"));
}

TEST(rToA, testWithFour)
{
    EXPECT_EQ(4, romanToArabic("IV"));
}

TEST(rToA, testWithNine)
{
    EXPECT_EQ(9, romanToArabic("IX"));
}

TEST(rToA, testWithForty)
{
    EXPECT_EQ(40, romanToArabic("XL"));
}

TEST(rToA, testWithNinety)
{
    EXPECT_EQ(90, romanToArabic("XC"));
}

TEST(rToA, testWithFourHundred)
{
    EXPECT_EQ(400, romanToArabic("CD"));
}

TEST(rToA, testWithNineHundred)
{
    EXPECT_EQ(900, romanToArabic("CM"));
}

TEST(vNum, testWithValidNumber)
{
    EXPECT_TRUE(validateNumber("4"));
}

TEST(vNum, testWithBarelyTooLargeNumber)
{
    EXPECT_TRUE(!validateNumber("4000"));
}

TEST(vNum, testWithBarelyTooSmallNumber)
{
    EXPECT_TRUE(!validateNumber("0"));
}

TEST(vNum, testWithWayTooLargeNumber)
{
    EXPECT_TRUE(!validateNumber("40000000000000"));
}

TEST(vNum, testWithEmptyString)
{
    EXPECT_TRUE(!validateNumber(""));
}

TEST(vNum, testWithInvalidShortString)
{
    EXPECT_TRUE(!validateNumber("a"));
}

TEST(vNum, testWithLeadingZeros)
{
    EXPECT_TRUE(!validateNumber("012"));
}

TEST(vStr, testWithValidRomanNumeral)
{
    EXPECT_TRUE(validateString("IV"));
}

TEST(vStr, testWithOtherCharacters)
{
    EXPECT_TRUE(!validateString("ZY"));
}
