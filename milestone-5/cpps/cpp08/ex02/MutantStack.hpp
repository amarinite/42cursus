#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
		~MutantStack(void);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"