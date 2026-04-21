#pragma once
#include <cstdlib>

template <typename T, typename F>
void	iter(T *arrAddress, const size_t arrLength, F func)
{
	for (size_t i = 0; i < arrLength; i++)
		func(arrAddress[i]);
}