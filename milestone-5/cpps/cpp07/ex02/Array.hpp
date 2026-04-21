#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int 	_length;
		T* 				_arr;

	public:
		Array() : _length(0), _arr(new T[0])
		{	
		}

		Array(unsigned int n) : _length(n), _arr(new T[n])
		{
		}

		Array(const Array &other) : _length(other._length), _arr(new T[other._length])
		{
			for (unsigned int i = 0; i < _length; i++)
				_arr[i] = other._arr[i];
		}

		Array &operator=(const Array &other)
		{
			if (this == &other)
				return *this;
			delete[] _arr;
			_length = other._length;
			_arr = new T[_length];
			for (unsigned int i = 0; i < _length; i++)
				_arr[i] = other._arr[i];
			return *this;
		}

		~Array()
		{
			delete[] _arr;
		}

		unsigned int	size() const
		{
			return _length;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _length)
				throw std::out_of_range("Index out of bounds");
			return _arr[i];
		}

		const T& operator[](unsigned int i) const
		{
			if (i >= _length)
				throw std::out_of_range("Index out of bounds");
			return _arr[i];
		}
};

#endif