#pragma once
#include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);

		std::string	getType()	const;
		virtual void		makeSound() const = 0;

};