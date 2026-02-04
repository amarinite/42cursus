#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called\n";
	_type = "cat";
}


WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Cat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment called\n";
	if  (this == &other)
		return *this;
	
	this->_type = other._type;

	return *this;
}

std::string WrongCat::getType() const
{
	return _type;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat goes meow\n";
}
