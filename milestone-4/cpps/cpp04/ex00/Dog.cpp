#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called\n";
	_type = "dog";
}


Dog::~Dog()
{
	std::cout << "Dog default destructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment called\n";
	if  (this == &other)
		return *this;
	
	this->_type = other._type;

	return *this;
}

std::string Dog::getType() const
{
	return _type;
}

void Dog::makeSound() const
{
	std::cout << "Dog goes woof\n";
}
