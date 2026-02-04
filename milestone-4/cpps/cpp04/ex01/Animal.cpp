#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called\n";
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment called\n";
	if (this == &other)
		return *this;
	
	this->_type = other._type;

	return *this;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
}
