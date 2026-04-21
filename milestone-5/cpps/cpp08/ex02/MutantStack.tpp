template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &obj) : std::stack<T>(obj)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj)
{
	if (this != &obj)
		std::stack<T>::operator=(obj);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}