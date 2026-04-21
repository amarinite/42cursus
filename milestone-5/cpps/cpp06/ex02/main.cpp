#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <cstdlib>
# include <iostream>
# include <exception>


Base * generate(void)
{
	srand(time(0));
	int r = rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	if(a)
		std::cout << "Base type is A" << std::endl;
	if(b)
		std::cout << "Base type is B" << std::endl;
	if(c)
		std::cout << "Base type is C" << std::endl;

}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Base type (by reference) is A" << std::endl;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Base type (by reference) is B" << std::endl;
	} catch (const std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Base type (by reference) is C" << std::endl;
	} catch (const std::exception& e) {}
}

int	main(void)
{
	Base *random = generate();
	identify(random);
	identify(*random);
	delete(random);
	return 0;
}