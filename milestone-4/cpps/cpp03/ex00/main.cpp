#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "************ MANOLO IS BORN ************\n";
	ClapTrap manolo("manolo");
	manolo.attack("marisa");
	manolo.takeDamage(7);
	manolo.beRepaired(3);
	
	std::cout << "\n************ MANOLO WASTES HIS POINTS ************\n";
	manolo.attack("marisa");
	manolo.attack("marisa");
	manolo.attack("marisa");
	manolo.attack("marisa");
	manolo.beRepaired(3);
	manolo.beRepaired(10);
	manolo.beRepaired(3);
	manolo.attack("marisa");
	manolo.attack("marisa");
	manolo.attack("marisa");

	std::cout << "\n************ MANOLO DIES ************\n";
	manolo.takeDamage(12);
	manolo.attack("marisa");
	manolo.beRepaired(3);

	return 0;
}


