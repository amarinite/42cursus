#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called\n";
	_type = "cat";
	_brain = new Brain();
}


Cat::~Cat()
{
	std::cout << "Cat default destructor called\n";
	delete _brain;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called\n";
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment called\n";
	if (this == &other)
		return *this;
	
	this->_type = other._type;
	delete _brain;
	_brain = new Brain(*other._brain);

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
