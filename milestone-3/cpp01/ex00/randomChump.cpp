#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *randomZmb = newZombie(name);

	randomZmb->announce();

	delete(randomZmb);
}