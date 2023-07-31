#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(HelloTest, BasicAssertions){
    EXPECT_STRNE("Hello", "World");
    EXPECT_EQ(11*7, 77);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}