#include "Fixed.hpp"

int main( void )
{
	std::cout << "--- Increment/Decrement Operators ---" << std::endl;
	Fixed a(5.5f);
	
	std::cout << "Initial a: " << a << std::endl;
	std::cout << "++a (pre-increment): " << ++a << std::endl;
	std::cout << "a after ++a: " << a << std::endl;
	std::cout << "a++ (post-increment): " << a++ << std::endl;
	std::cout << "a after a++: " << a << std::endl;
	
	std::cout << "\n--a (pre-decrement): " << --a << std::endl;
	std::cout << "a after --a: " << a << std::endl;
	std::cout << "a-- (post-decrement): " << a-- << std::endl;
	std::cout << "a after a--: " << a << std::endl;

	std::cout << "\n--- Comparison Operators ---" << std::endl;
	Fixed b(5.05f);
	Fixed c(2.02f);
	std::cout << "b > c: " << (b > c) << std::endl;
	std::cout << "b < c: " << (b < c) << std::endl;
	std::cout << "b >= c: " << (b >= c) << std::endl;
	std::cout << "b <= c: " << (b <= c) << std::endl;
	std::cout << "b == c: " << (b == c) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\n--- Arithmetic Operators ---" << std::endl;
	Fixed d(10.5f);
	Fixed e(2.5f);
	std::cout << "d + e: " << (d + e) << std::endl;
	std::cout << "d - e: " << (d - e) << std::endl;
	std::cout << "d * e: " << (d * e) << std::endl;
	std::cout << "d / e: " << (d / e) << std::endl;

	std::cout << "\n--- Min/Max Functions ---" << std::endl;
	std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
	const Fixed constB(5.05f);
	const Fixed constC(2.02f);
	std::cout << "min(const constB, const constC): " << Fixed::min(constB, constC) << std::endl;
	std::cout << "max(const constB, const constC): " << Fixed::max(constB, constC) << std::endl;

	return 0;
}