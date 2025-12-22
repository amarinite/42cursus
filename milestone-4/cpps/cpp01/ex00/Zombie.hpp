#pragma once

# include <string>
# include <iostream>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie(const std::string nm);
		~Zombie();

		void		announce(void) const;
		std::string	getName(void) const;
};

Zombie	*newZombie(std::string name );
void	randomChump(std::string name );