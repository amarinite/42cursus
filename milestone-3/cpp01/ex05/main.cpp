#include <iostream>
#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	std::cout << "Testing Harl complaints:\n\n";

	harl.complain("DEBUG");

	harl.complain("INFO");

	harl.complain("WARNING");

	harl.complain("ERROR");
	
	std::cout << "Testing invalid level:\n";
	harl.complain("INVALID");
	std::cout << "(no output for invalid level)\n";

	return 0;
}