#include <iostream>
#include "iter.hpp"

void	incrementNumber(int& num)
{
	num++;
}

void	printNumber(const int& num)
{
	std::cout << num << std::endl;
}

void	toUpper(std::string &stri)
{
	for (size_t i = 0; i < stri.length(); i++)
		stri[i] = std::toupper(static_cast<unsigned char>(stri[i]));
}

void	printString(const std::string &stri)
{
	std::cout << stri << std::endl;
}

int main( void )
{
	int	nums[5] = {1, 2, 3, 4, 5};
	std::string strings[3] = {"Hola buenas", "adios a todos", "chau"};

	::iter(nums, 5, incrementNumber);
	::iter(nums, 5, printNumber);

	::iter(strings, 3, toUpper);
	::iter(strings, 3, printString);

	const std::string strungs[3] = {"Hola buenas", "adios a todos", "chau"};
	::iter(strungs, 3, printString);

	return 0;
}

// #include <iostream>
// #include "iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   const int len = 5;

//   iter( tab, len, print<const int> );
//   iter( tab2, len, print<Awesome> );

//   return 0;
// }
