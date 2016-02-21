#include "../../src/Buffer.cpp"
#include <gtest/gtest.h>

TEST(BufferTest, BASIC){
	Buffer bf ("buffer", 3);
	ASSERT_STRCASEEQ("buffer", bf.getIdentifier());
	ASSERT_EQ(3, bf.getSize());
	bf.resize(1);
	ASSERT_EQ(1, bf.getSize());
	bf.setIdentifier("newName");
	ASSERT_STRCASEEQ("newName", bf.getIdentifier());
}

TEST(BufferTest, push_pop_get){
	Buffer bf ("size3", 3);
	bf.push("a");
	ASSERT_STRCASEEQ("a", bf.get());
	bf.push("b");
	ASSERT_STRCASEEQ("b", bf.get());
	bf.push("c");
	ASSERT_STRCASEEQ("c", bf.get());
	bf.push("d");
	ASSERT_STRCASEEQ("d", bf.get());
	
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
