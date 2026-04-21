#include "Span.hpp"

Span::Span(unsigned int capacity) : _max_capacity(capacity), vec(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &other) : _max_capacity(other._max_capacity), vec(other.vec)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max_capacity = other._max_capacity;
		vec = other.vec;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (vec.size() >= _max_capacity)
		throw std::out_of_range("Span is full");
	vec.push_back(num);
}

void Span::addNumberRange(const std::vector<int> &vecRange)
{
	if (vecRange.size() > (_max_capacity - vec.size()))
		throw std::out_of_range("Span is full");
	
	vec.insert(vec.end(), vecRange.begin(), vecRange.end());
}

int Span::shortestSpan() const
{
	if (vec.size() < 2)
		throw std::logic_error("Span is too short (must be bigger than 1)");

	std::vector<int> tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (vec.size() < 2)
		throw std::logic_error("Span is too short (must be bigger than 1)");
	
	int min_value = *std::min_element(vec.begin(), vec.end());
	int max_value = *std::max_element(vec.begin(), vec.end());

	return max_value - min_value;
}

const std::vector<int> &Span::getVec() const
{
	return vec;
}

unsigned int Span::getMaxCapacity() const
{
	return _max_capacity;
}

std::ostream &operator<<(std::ostream &os, const Span &sp)
{
	const std::vector<int> &v = sp.getVec();

	os << "[";
	for (size_t i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i + 1 < v.size())
			os << ", ";
	}
	os << "]";
	return os;
}