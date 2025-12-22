#include "Weapon.hpp"

Weapon::Weapon(const std::string &wpn)
{
	type = wpn;
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &tp)
{
	if (!tp.empty())
		type = tp;
}
