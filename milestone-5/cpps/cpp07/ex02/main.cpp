#include <iostream>
#include "Array.hpp"

int main( void )
{
	// int * a = new int();

	// std::cout << *a << std::endl;
	// delete a;

	// Test with int
	Array<int> intArr(5);
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i * 10;
	std::cout << "Int array: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	// Test with double
	Array<double> doubleArr(3);
	doubleArr[0] = 1.1;
	doubleArr[1] = 2.2;
	doubleArr[2] = 3.3;
	std::cout << "Double array: ";
	for (unsigned int i = 0; i < doubleArr.size(); i++)
		std::cout << doubleArr[i] << " ";
	std::cout << std::endl;

	// Test with string
	Array<std::string> strArr(3);
	strArr[0] = "hello";
	strArr[1] = "world";
	strArr[2] = "!";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	// Test copy constructor
	Array<int> intArrCopy(intArr);
	intArrCopy[0] = 999;
	std::cout << "Original int array after copy modification: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	// Test assignment operator
	Array<int> intArrAssign;
	intArrAssign = intArr;
	intArrAssign[0] = 888;
	std::cout << "Original int array after assign modification: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	// Test out of bounds exception
	try
	{
		std::cout << intArr[999] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}