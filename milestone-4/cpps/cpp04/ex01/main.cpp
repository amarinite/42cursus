#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal *animals[6];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Dog();
			std::cout << "\e[32mI created a dog\e[0m\n";
		}
		else
		{
			animals[i] = new Cat();
			std::cout << "\e[32mI created a cat\e[0m\n";
		}
	}

	for (int i = 0; i < 6; i++)
		delete animals[i];

	// std::cout << "\n\e[33m=== Testing Deep Copy ===\e[0m\n";
	// Dog originalDog;
	// Dog copiedDog = originalDog;
	// std::cout << "Original dog address: " << &originalDog << "\n";
	// std::cout << "Copied dog address: " << &copiedDog << "\n";

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// delete j;
	// delete i;

	return 0;
}