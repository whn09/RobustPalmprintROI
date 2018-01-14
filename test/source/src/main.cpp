/*************************************************************************
> File Name: main.cpp
> Author: Leosocy
> Mail: 513887568@qq.com
> Created Time: 2018/1/14 12:04:38
************************************************************************/
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(filter) = "*";
    return RUN_ALL_TESTS();
}
