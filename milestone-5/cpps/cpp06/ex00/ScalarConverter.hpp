#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void	convert(const std::string& literal);
};

#endif

