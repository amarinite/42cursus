#include "ScalarConverter.hpp"

enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, ERROR };

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static Type detectType(const std::string &literal)
{
	const size_t len = literal.length();

	const std::string pseudoLits[6] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++)
		if (literal == pseudoLits[i])
			return PSEUDO;

	if (len == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		if (isascii(literal[1]))
			return CHAR;
		return ERROR;
	}

	const size_t dotPos = literal.find('.');
	if (dotPos != std::string::npos)
	{
		if (dotPos == 0 || dotPos == len - 1)
			return ERROR;
		const size_t end = (literal[len - 1] == 'f') ? len - 1 : len;
        for (size_t i = dotPos + 1; i < end; i++)
            if (!isdigit(literal[i]))
                return ERROR;
        if (literal[len - 1] == 'f' && dotPos == len - 2)
            return ERROR;
        if (literal[len - 1] == 'f')
            return FLOAT;
        return DOUBLE;
	}
	
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    const bool hasF = (literal[len - 1] == 'f' && len - 1 != i);
    for (size_t j = i; j < (hasF ? len - 1 : len); j++)
        if (!isdigit(literal[j]))
            return ERROR;
    return hasF ? FLOAT : INT;
}

static void printChar(const std::string &literal, Type type)
{
	if (type == PSEUDO)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	double value;
	if (type == CHAR)
		value = literal[1];
	else
		value = std::strtod(literal.c_str(), NULL);

	if (value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(value);
	if (!isprint(c))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}

	std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(const std::string &literal, Type type)
{
	if (type == PSEUDO)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	double value;
	if (type == CHAR)
		value = literal[1];
	else
		value = std::strtod(literal.c_str(), NULL);
	if (value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(const std::string &literal, Type type)
{
	if (type == PSEUDO)
	{
		if (literal == "nan" || literal == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "float: +inff" << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << "float: -inff" << std::endl;
		return ;
	}
	
	double value;
	if (type == CHAR)
		value = literal[1];
	else
		value = std::strtod(literal.c_str(), NULL);

	float f = static_cast<float>(value);
	if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

static void printDouble(const std::string &literal, Type type)
{
	if (type == PSEUDO)
	{
		if (literal == "nan" || literal == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (literal == "+inf" || literal == "+inff")
			std::cout << "double: +inf" << std::endl;
		else if (literal == "-inf" || literal == "-inff")
			std::cout << "double: -inf" << std::endl;
		return ;
	}
	
	double value;
	if (type == CHAR)
		value = static_cast<double>(literal[1]);
	else
		value = std::strtod(literal.c_str(), NULL);

	if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	Type type = detectType(literal);
	if (type == ERROR)
	{
		std::cerr << "Error: unrecognized literal" << std::endl; 
		return ;
	}
	printChar(literal, type);
	printInt(literal, type);
	printFloat(literal, type);
	printDouble(literal, type);
}



