#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << CYAN"[ DEBUG ]\n" << 
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" 
	<< NC;
}

void	Harl::info(void)
{
	std::cout << GREEN"[ INFO ]\n" << 
	"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
	<< NC;
}

void	Harl::warning(void)
{
	std::cout << YELLOW"[ WARNING ]\n" <<
	"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n"
	<< NC;
}

void	Harl::error(void)
{
	std::cout << RED"[ ERROR ]"
	"This is unacceptable! I want to speak to the manager now.\n" 
	<< NC;
}

void	Harl::complain(std::string level)
{
	int levelIndex = -1;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
