#pragma once
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
		unsigned int _max_capacity;
		std::vector<int> vec;

	public:
		Span(unsigned int capacity);
		~Span();
		Span (const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int num);
		void addNumberRange(const std::vector<int> &vecRange);
		int shortestSpan() const;
		int longestSpan() const;

		const std::vector<int> &getVec() const;
		unsigned int getMaxCapacity() const;
};
std::ostream &operator<<(std::ostream &os, const Span &sp);
