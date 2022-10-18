#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        size_t  _size;
        T       *array;
    
    public:
        Array()
        {
            this->_size = 0;
            this->array = new T[this->_size];
        };

        Array(unsigned int n)
        {
            this->_size = n;
            this->array = new T[this->_size];
        };

        Array(const Array &copy)
        {
            this->_size = copy._size;
            this->array = new T[this->_size];
            for (int i = 0; i < this->_size; i++)
                this->array[i] = copy[i];
        }

        ~Array()
        {
            delete[] this->array;
        }

        Array &operator=(const Array &copy)
        {
            this->~Array();
            this->_size = copy._size;
            this->array = new T[this->_size];
            for (int i = 0; i < this->_size; i++)
                this->array[i] = copy[i];
            return (*this);
        }

        T &operator[](size_t i) const
        {
            if (i < 0 || i >= this->_size)
                throw Array::OutOfRangeException();
            return (this->array[i]);
        }

        size_t size()
        {
            return (this->_size);
        }

        class OutOfRangeException : public std::exception
        {
            public:
                char *what() const throw()
                {
                    return ((char *)"number out of range.");
                }
        };
};

#endif
