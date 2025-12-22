#pragma once

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(const std::string &nm);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon *wpn);
};
