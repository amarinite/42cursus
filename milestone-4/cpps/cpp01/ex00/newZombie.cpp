#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *nZmb = new Zombie(name);

	return nZmb;
}