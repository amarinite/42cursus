#include "HumanA.hpp"

HumanA::HumanA(const std::string &nm, Weapon &wpn) : name(nm), weapon(wpn)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << name <<" attacks with their " << weapon.getType() << '\n';
}
