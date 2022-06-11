#include "gtest/gtest.h"

extern "C" {
#include "instance.h"
}

class Buf : public ::testing::Test
{
protected:
	static void TearDownTestCase()
	{
		get_instance()->destroy();
	}

	virtual void SetUp() override
	{
		get_instance()->buf_start();
	}

	virtual void TearDown() override
	{
		get_instance()->buf_stop();
	}
};

TEST_F(Buf, start)
{

	// Arrange

	// Act

	// Assert
	ASSERT_EQ(get_instance()->buffer->capacity, 256);
	ASSERT_EQ(get_instance()->buffer->used, 0);
}

TEST_F(Buf, push_back_without_capacity_growth)
{
	// Arrange
	const char* str = "say_hi";

	// Act
	get_instance()->buf_pushback(str);

	// Assert
	ASSERT_STREQ(get_instance()->buffer->data, str);
	ASSERT_EQ(get_instance()->buffer->used, strlen(str));
}

TEST_F(Buf, push_back_with_capacity_growth)
{
	// Arrange
	const char* str = "say_hi";

	// Act
	for (; get_instance()->buffer->used < 256; get_instance()->buf_pushback(str));

	// Assert
	ASSERT_EQ(get_instance()->buffer->capacity, 512);
}

TEST_F(Buf, stop)
{

	// Arrange

	// Act
	get_instance()->buf_stop();

	// Assert
	ASSERT_EQ(get_instance()->buffer->used, 0);
	ASSERT_TRUE(get_instance()->buffer->data == NULL);
}