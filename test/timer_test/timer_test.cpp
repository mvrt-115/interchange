#include "../../src/CppTimer.cpp"
#include <gtest/gtest.h>
#include <utility>
#include <chrono>

/**
	Create a test:
**/

TEST(TimerTest, timeCheck_0)
{
    CppTimer timer(0);
    sleep(1000);
    ASSERT_EQ(1, timer.getTime().get(0));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
