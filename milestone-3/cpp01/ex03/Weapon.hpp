#pragma once

#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(const std::string &wpn);
		~Weapon();

		std::string	getType() const;
		void	setType(const std::string &tp);
};