#include "gtest/gtest.h"
#include <set>

extern "C" {
#include "instance.h"
#include "executer.h"
}

extern char** my_argv;

std::set<std::string>& split(const std::string& s, char delim, std::set<std::string>& elems)
{
	std::stringstream ss(s);
	std::string token;
	while (std::getline(ss, token, delim))
	{
		elems.insert(token);
	}
	return elems;
}

class Exec : public ::testing::Test
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

TEST_F(Exec, suite1)
{
	// Arrange
	std::set<std::string> expected = {
			"./file3", "./file2", "./file9", "./file8", "./file1", "./file4", "./file7", "./file10", "./file6",
			"./file5"
	};
	std::set<std::string> actual;
	std::string path = my_argv[1];
	path.append("/suite1");


	// Act
	testing::internal::CaptureStdout();
	start_iteration(path.data());
	std::string output = testing::internal::GetCapturedStdout();

	split(output, '\n', actual);

	// Assert
	for (const auto& elem: expected)
	{
		auto search = actual.find(elem);
		ASSERT_NE(search, actual.end());

		actual.erase(search);
	}

	ASSERT_TRUE(actual.empty());
}

TEST_F(Exec, suite2)
{
	// Arrange
	std::set<std::string> expected = {
			"./file2", "./file1", "./dir2", "./dir2/file2", "./dir2/file1", "./dir2/dir1", "./dir2/dir1/file2",
			"./dir2/dir1/file1", "./dir2/dir1/dir2", "./dir2/dir1/dir2/file2", "./dir2/dir1/dir2/file1", "./dir1",
			"./dir1/file2", "./dir1/file1", "./dir1/dir2", "./dir1/dir2/file2", "./dir1/dir2/file1"
	};
	std::set<std::string> actual;
	std::string path = my_argv[1];
	path.append("/suite2");


	// Act
	testing::internal::CaptureStdout();
	start_iteration(path.data());
	std::string output = testing::internal::GetCapturedStdout();

	split(output, '\n', actual);

	// Assert
	for (const auto& elem: expected)
	{
		auto search = actual.find(elem);
		ASSERT_NE(search, actual.end());

		actual.erase(search);
	}

	ASSERT_TRUE(actual.empty());
}