#include "HumanB.hpp"

HumanB::HumanB(const std::string &nm) : name(nm)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
	if (weapon != NULL)
		std::cout << name <<" attacks with their " << weapon->getType() << '\n';
	else
		std::cout << name <<" has no weapon\n";
}

void HumanB::setWeapon(Weapon *wpn)
{
	weapon = wpn;
}
