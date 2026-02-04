#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap manolo("manolo");
	ScavTrap marisa("marisa");

	manolo.attack("marisa");
	marisa.attack("manolo");

	marisa.guardGate();

	return 0;
}


