#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap manolo("manolo");
	FragTrap manuela("manuela");

	manolo.attack("marisa");
	manuela.attack("manolo");

	manuela.highFivesGuys();

	return 0;
}


