#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

void Zombie::setName(const std::string &nm)
{
	name = nm;
}

std::string Zombie::getName(void) const
{
	return name;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed\n";
}

void Zombie::announce(void) const
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ...\n";
}