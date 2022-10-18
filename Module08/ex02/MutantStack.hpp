#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : MutantStack<T>::stack(){};
        MutantStack(const MutantStack &copy) : MutantStack<T>::stack(copy){};
        MutantStack<T> &operator=(const MutantStack<T> &copy)
        {
            if (this != &copy)
	        {
	        	MutantStack<T>::stack::operator=(copy);
	        }
            return *this;
        };
        ~MutantStack(){};

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin()
        {
            return(this->c.begin());
        };
        iterator end()
        {
            return(this->c.end());
        };

};

#endif
