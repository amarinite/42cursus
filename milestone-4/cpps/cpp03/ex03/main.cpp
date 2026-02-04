#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "************ MANOLO THE DIAMOND IS BORN ************\n";
	DiamondTrap manolo("Manolo");

	manolo.whoAmI();
	manolo.attack("Marisa");
	manolo.takeDamage(40);
	manolo.beRepaired(20);

	std::cout << "\n************ MANOLO GUARDS ************\n";
	manolo.guardGate();

	std::cout << "\n************ MANOLO HIGH-FIVES ************\n";
	manolo.highFivesGuys();

	std::cout << "\n************ MANOLO COPIES HIMSELF ************\n";
	DiamondTrap copyManolo(manolo);
	copyManolo.whoAmI();
	copyManolo.attack("Marisa");

	std::cout << "\n************ MANOLO GETS ASSIGNED ************\n";
	DiamondTrap assigned;
	assigned = manolo;
	assigned.whoAmI();

	std::cout << "\n************ MANOLO TAKES FATAL DAMAGE ************\n";
	manolo.takeDamage(200);
	manolo.attack("Marisa");
	manolo.beRepaired(50);

	return 0;
}


