#include "cxxtest/TestSuite.h"

#include "utility/file/FilePath.h"

class FilePathTestSuite : public CxxTest::TestSuite
{
public:
	void test_file_path_gets_created_with_char_array()
	{
		FilePath path("data/FilePathTestSuite/main.cpp");

		TS_ASSERT_EQUALS(path.str(), "data/FilePathTestSuite/main.cpp");
	}

	void test_file_path_gets_created_with_string()
	{
		std::string str("data/FilePathTestSuite/main.cpp");
		FilePath path(str);

		TS_ASSERT_EQUALS(path.str(), str);
	}

	void test_file_path_gets_created_other_file_path()
	{
		FilePath path("data/FilePathTestSuite/main.cpp");
		FilePath path2(path);

		TS_ASSERT_EQUALS(path, path2);
	}

	void test_file_path_exists()
	{
		FilePath path("data/FilePathTestSuite/a.cpp");

		TS_ASSERT(path.exists());
	}

	void test_file_path_not_exists()
	{
		FilePath path("data/FilePathTestSuite/a.h");

		TS_ASSERT(!path.exists());
	}

	void test_file_path_file_name()
	{
		FilePath path("data/FilePathTestSuite/abc.h");

		TS_ASSERT_EQUALS(path.fileName(), "abc.h");
	}

	void test_file_path_extension()
	{
		FilePath path("data/FilePathTestSuite/a.h");

		TS_ASSERT_EQUALS(path.extension(), ".h");
	}

	void test_file_path_without_extension()
	{
		FilePath path("data/FilePathTestSuite/a.h");

		TS_ASSERT_EQUALS(path.withoutExtension(), "data/FilePathTestSuite/a");
	}

	void test_file_path_has_extension()
	{
		std::vector<std::string> extensions;
		extensions.push_back(".h");
		extensions.push_back(".cpp");
		extensions.push_back(".cc");

		TS_ASSERT(FilePath("data/FilePathTestSuite/a.h").hasExtension(extensions));
		TS_ASSERT(FilePath("data/FilePathTestSuite/b.cpp").hasExtension(extensions));
		TS_ASSERT(!FilePath("data/FilePathTestSuite/a.m").hasExtension(extensions));
	}

	void test_file_path_equals_file_with_different_relative_paths()
	{
		FilePath pathA("data/FilePathTestSuite/a.cpp");
		FilePath pathA2("data/../data/FilePathTestSuite/./a.cpp");

		TS_ASSERT_EQUALS(pathA, pathA2);
	}

	void test_file_path_equals_relative_and_absolute_paths()
	{
		FilePath pathA("data/FilePathTestSuite/a.cpp");
		FilePath pathA2(pathA.absoluteStr());

		TS_ASSERT_EQUALS(pathA, pathA2);
	}

	void test_file_path_compares_paths_with_posix_and_windows_format()
	{
#ifdef _WIN32
		FilePath pathB("data/FilePathTestSuite/b.cc");
		FilePath pathB2("data\\FilePathTestSuite\\b.cc");

		TS_ASSERT_EQUALS(pathB, pathB2);
#endif
	}

	void test_file_path_differs_for_different_existing_files()
	{
		FilePath pathA("data/FilePathTestSuite/a.cpp");
		FilePath pathB("data/FilePathTestSuite/b.cc");

		TS_ASSERT_DIFFERS(pathA, pathB);
	}

	void test_file_path_differs_for_different_nonexisting_files()
	{
		FilePath pathA("data/FilePathTestSuite/a.h");
		FilePath pathB("data/FilePathTestSuite/b.c");

		TS_ASSERT_DIFFERS(pathA, pathB);
	}

	void test_file_path_differs_for_existing_and_nonexisting_files()
	{
		FilePath pathA("data/FilePathTestSuite/a.h");
		FilePath pathB("data/FilePathTestSuite/b.cc");

		TS_ASSERT_DIFFERS(pathA, pathB);
	}
};
