#include "Zombie.hpp"

Zombie::Zombie(std::string nm)
{
	name = nm;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed\n";
}

std::string	Zombie::getName(void) const
{
	return name;
}

void	Zombie::announce(void) const
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}