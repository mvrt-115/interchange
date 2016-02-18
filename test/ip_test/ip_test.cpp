#include "../../src/IPAddr.cpp"
#include <gtest/gtest.h>

/**
	The tests to done by this are:
	- the getIPString
	- Check whether the INT way and the STR way work the same
		- constructors
		- setAddr

Also, make sure that the things put in are whole numbers.
**/

// function(expected, actual)

TEST(IPTest, const_int_getIPString)
{
    IPAddr test(123, 456, 7, 890);
    ASSERT_STRCASEEQ("123456007890", test.getIPString().c_str());
}

TEST(IPTest, const_string_getIPString)
{
    IPAddr test("123456007890");
    ASSERT_STRCASEEQ("123456007890", test.getIPString().c_str());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
