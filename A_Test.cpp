#include <iostream>
#include "gtest/gtest.h"
#include "A.cpp"

#ifdef TEST_ON

TEST(correctness, 0)
{
    uint array[] = {
            2,
            1, 1,
            1, 2,
    };

    ASSERT_EQ(1, a_work(array[0], array + 1));
}

TEST(correctness, 1)
{
    uint array[] = {
            2,
            1, 2,
            1, 2,
    };

    ASSERT_EQ(2, a_work(array[0], array + 1));
}

TEST(correctness, 2)
{
    uint array[] = {
            6,
            1, 0,
            1, 3,
            2, 4,
            1, 5,
            1, 1,
            1, 0,
    };

    ASSERT_EQ(4, a_work(array[0], array + 1));
}

TEST(correctness, 3)
{
    uint array[] = {
            5,
            1, 5,
            1, 4,
            1, 3,
            1, 2,
            2, 100,
    };

    ASSERT_EQ(9, a_work(array[0], array + 1));
}

TEST(correctness, 4)
{
    uint array[] = {
            6,
            1, 5,
            1, 4,
            1, 3,
            1, 2,
            2, 100,
            2, 120,
    };

    ASSERT_EQ(14, a_work(array[0], array + 1));
}

TEST(correctness, 5)
{
    uint array[] = {
            6,
            1, 1,
            2, 2,
            3, 3,
            4, 4,
            5, 5,
            6, 6,
    };

    ASSERT_EQ(0, a_work(array[0], array + 1));
}

TEST(correctness, 6)
{
    uint array[] = {
            6,
            1, 1,
            2, 2,
            3, 3,
            4, 4,
            5, 5,
            2, 6,
    };

    ASSERT_EQ(1, a_work(array[0], array + 1));
}

TEST(correctness, 7)
{
    uint array[] = {
            4,
            1, 15,
            2, 100,
            2, 25,
            1, 30,
    };

    ASSERT_EQ(40, a_work(array[0], array + 1));
}

TEST(correctness, 8)
{
    uint array[] = {
            3,
            1, 15,
            100, 100,
            100, 100,
    };

    ASSERT_EQ(0, a_work(array[0], array + 1));
}

TEST(correctness, 9)
{
    uint array[] = {
            3,
            1, 15,
            0, 100,
            100, 100,
    };

    ASSERT_EQ(100, a_work(array[0], array + 1));
}

TEST(correctness, 10)
{
    uint array[] = {
            3,
            1, 15,
            2, 100,
            100, 100,
    };

    ASSERT_EQ(0, a_work(array[0], array + 1));
}

TEST(correctness, 11)
{
    uint array[] = {
            4,
            1, 15,
            3, 100,
            3, 200,
            100, 100,
    };

    ASSERT_EQ(0, a_work(array[0], array + 1));
}

TEST(correctness, 12)
{
    uint array[] = {
            6,
            1, 1,
            3, 3,
            3, 3,
            3, 3,
            3, 3,
            4, 100,
    };

    ASSERT_EQ(4, a_work(array[0], array + 1));
}

TEST(correctness, 13)
{
    uint array[] = {
            6,
            1, 1,
            5, 3,
            5, 3,
            5, 3,
            5, 3,
            6, 100,
    };

    std::string input = R"INPUT(
            6
            1 1
            5 3
            5 3
            5 3
            5 3
            6 100
            )INPUT";


    ASSERT_EQ(0, a_work(array[0], array + 1));
}


TEST(correctness, 14)
{
    uint array[] = {
            4,
            3, 4,
            3, 2,
            1, 1,
            3, 2,
    };

    ASSERT_EQ(1, a_work(array[0], array + 1));
}

TEST(correctness, 15)
{
    uint array[] = {
            4,
            1, 10000000000,
            1, 10000000000,
            1, 10000000000,
            1, 10000000000,
    };

    ASSERT_EQ(30000000000, a_work(array[0], array + 1));
}

TEST(correctness, 16)
{
    uint array[] = {
            10,
            5, 2,
            0, 0,
            3, 9,
            1, 8,
            1, 9,
            5, 3,
            2, 5,
            2, 5,
            8, 6,
            7, 7,
    };

    ASSERT_EQ(13, a_work(array[0], array + 1));
}

#endif /// TEST_ON == 1
