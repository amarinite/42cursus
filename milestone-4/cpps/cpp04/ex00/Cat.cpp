#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	_type = "cat";
}


Cat::~Cat()
{
	std::cout << "Cat default destructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment called\n";
	if  (this == &other)
		return *this;
	
	this->_type = other._type;

	return *this;
}

std::string Cat::getType() const
{
	return _type;
}

void Cat::makeSound() const
{
	std::cout << "Cat goes meow\n";
}
