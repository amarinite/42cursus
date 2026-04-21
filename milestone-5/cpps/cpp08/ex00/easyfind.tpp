
template <typename T>
typename T::const_iterator easyfind(T &type, int num)
{
	typename T::const_iterator it = std::find(type.begin(), type.end(), num); 

	if (it == type.end())
		throw std::out_of_range("easyfind: value not found");

	return it;
}
