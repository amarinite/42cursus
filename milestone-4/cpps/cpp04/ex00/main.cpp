#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	// const WrongAnimal* wrongMeta = new WrongAnimal();
	// const WrongAnimal* mistake = new WrongCat();

	// std::cout << mistake->getType() << " " << std::endl;
	// mistake->makeSound();
	// wrongMeta->makeSound();

	// delete(wrongMeta);
	// delete(mistake);

	delete(meta);
	delete(i);
	delete(j);
	
	return 0;
}