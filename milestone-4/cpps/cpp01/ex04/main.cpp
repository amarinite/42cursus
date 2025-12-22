#include <iostream>
#include <fstream>

#include "ex04.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		// (void)argv;
		// execute_tests();
		return replace_file(argv);
	}
	else
		std::cout << "Program must be executed with <filename> <s1> <s2>\n";
	return 0;
}