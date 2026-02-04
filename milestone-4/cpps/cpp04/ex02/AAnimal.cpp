#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
	std::cout << "Animal default constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "Animal default destructor called\n";
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal copy assignment called\n";
	if (this == &other)
		return *this;
	
	this->_type = other._type;

	return *this;
}

std::string AAnimal::getType() const
{
	return _type;
}

void AAnimal::makeSound() const
{
}
