#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	Data original;
	original.id = 42;
	original.name = "test";
	original.isActive = true;

	std::cout << YELLOW << "Original pointer address: " << RESET << &original << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << YELLOW <<  "Serialized value: " << RESET << raw << std::endl;

	Data *deserialized = Serializer::deserialize(raw);
	std::cout << YELLOW <<  "Deserialized pointer address: " << RESET << deserialized << std::endl;

	std::cout << GREEN << "Pointers match: " << (&original == deserialized ? "YES" : "NO") << RESET << std::endl;

	std::cout << YELLOW << "\nDeserialized data:" << RESET << std::endl;
	std::cout << "  id: " << deserialized->id << std::endl;
	std::cout << "  name: " << deserialized->name << std::endl;
	std::cout << "  isActive: " << deserialized->isActive << std::endl;

	return (0);
}