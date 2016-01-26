#include <gtest/gtest.h>
#include <iostream>

std::string arabicToRoman(int n)
{
    return "I";
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
