#pragma once

template <typename T>
void	swap(T &param1, T &param2)
{
	T tmp = param1;
	param1 = param2;
	param2 = tmp;
}

template <typename T>
T	min(T param1, T param2)
{
	return param1 < param2 ? param1 : param2;
}

template <typename T>
T	max(T param1, T param2)
{
	return param1 > param2 ? param1 : param2;
}