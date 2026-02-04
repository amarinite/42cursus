#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\e[1;33m=== Testing Abstract Class AAnimal ===\e[0m\n\n";

	std::cout << "\e[36mCreating a Dog and Cat:\e[0m\n";
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << "\n\e[36mCalling makeSound() through abstract class pointers:\e[0m\n";
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n\e[36mTesting Brain copy with assignment:\e[0m\n";
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();
	std::cout << "\e[32mAssigning dog1 to dog2 (triggers copy assignment)\e[0m\n";
	*dog2 = *dog1;

	std::cout << "\n\e[36mTesting Brain copy with copy constructor:\e[0m\n";
	std::cout << "\e[32mCreating dog3 as a copy of dog1\e[0m\n";
	Dog* dog3 = new Dog(*dog1);

	std::cout << "\n\e[36mCleaning up:\e[0m\n";
	delete dog;
	delete cat;
	delete dog1;
	delete dog2;
	delete dog3;

	std::cout << "\n\e[1;32m=== All tests completed successfully ===\e[0m\n";

	return 0;
}