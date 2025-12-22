#pragma once

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();

		void		announce(void) const;
		std::string	getName(void) const;
		void		setName(const std::string &nm);
};

Zombie*	zombieHorde( int N, std::string name );