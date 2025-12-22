#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "ex04.hpp"

void	create_test_file_empty(const std::string &filename)
{
	std::ofstream	testfile(filename.c_str());
	if (!testfile.is_open())
	{
		std::cerr << "Could not create test file\n";
		return;
	}
	testfile.close();
}

void	create_test_file_content(const std::string &filename)
{
	std::ofstream	testfile(filename.c_str());
	if (!testfile.is_open())
	{
		std::cerr << "Could not create test file\n";
		return;
	}
	testfile << "This is the first line\n";
	testfile << "This line has some content to replace\n";
	testfile << "Another line with more text\n";
	testfile.close();
}

void	create_test_file_no_read_permissions(const std::string &filename)
{
	std::ofstream	testfile(filename.c_str());
	if (!testfile.is_open())
	{
		std::cerr << "Could not create test file\n";
		return;
	}
	testfile << "This is the first line\n";
	testfile << "This line has some content to replace\n";
	testfile.close();

	if (chmod(filename.c_str(), S_IWUSR | S_IWGRP | S_IWOTH) == -1)
	{
		return;
	}
}

void	remove_test_file(const std::string &filename)
{
	if (std::remove(filename.c_str()) == -1)
	{
		std::cerr << "Could not remove file: " << filename << "\n";
		return;
	}
	std::cout << "File removed: " << filename << "\n";
}

void	execute_tests(void)
{
	std::cout << "=== Test 1: Empty file ===" << std::endl;
	create_test_file_empty("test_empty.txt");
	const char *argv1[] = {"ex04", "test_empty.txt", "search", "replace", NULL};
	if (replace_file((char **)argv1) == 0)
		std::cout << "✓ Test 1 PASSED\n" << std::endl;

	std::cout << "=== Test 2: File with content, no match ===" << std::endl;
	create_test_file_content("test_no_match.txt");
	const char *argv2[] = {"ex04", "test_no_match.txt", "nonexistent", "replacement", NULL};
	if (replace_file((char **)argv2) == 0)
		std::cout << "✓ Test 2 PASSED\n" << std::endl;

	std::cout << "=== Test 3: File with content, with match ===" << std::endl;
	create_test_file_content("test_with_match.txt");
	const char *argv3[] = {"ex04", "test_with_match.txt", "content", "REPLACED", NULL};
	if (replace_file((char **)argv3) == 0)
		std::cout << "✓ Test 3 PASSED\n" << std::endl;

	std::cout << "=== Test 4: File with no read permissions ===" << std::endl;
	create_test_file_no_read_permissions("test_no_perms.txt");
	const char *argv4[] = {"ex04", "test_no_perms.txt", "search", "replace", NULL};
	if (replace_file((char **)argv4) != 0)
		std::cout << "✓ Test 4 PASSED (correctly failed)\n" << std::endl;

	std::cout << "=== Test 5: Empty s1 (string to replace) ===" << std::endl;
	create_test_file_content("test_empty_s1.txt");
	const char *argv5[] = {"ex04", "test_empty_s1.txt", "", "replacement", NULL};
	if (replace_file((char **)argv5) != 0)
		std::cout << "✓ Test 5 PASSED (correctly failed)\n" << std::endl;

	std::cout << "=== Test 6: Empty s2 (should omit s1 occurrences) ===" << std::endl;
	create_test_file_content("test_empty_s2.txt");
	const char *argv6[] = {"ex04", "test_empty_s2.txt", "content", "", NULL};
	if (replace_file((char **)argv6) == 0)
		std::cout << "✓ Test 6 PASSED\n" << std::endl;

	std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
}