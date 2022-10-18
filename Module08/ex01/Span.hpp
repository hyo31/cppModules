#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
    private:
        std::vector<int>    array;
        unsigned int        size;

    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span(){};

        void            addNumber(int num);
        void            addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void            print() const;
        unsigned  int   shortestSpan() const;
        unsigned  int   longestSpan() const;
    
    class Full : public std::exception
    {
        public:
            char *what() const throw()
            {
                return ((char *)"Class is full.");
            }
    };

    class NotEnough : public std::exception
    {
        public:
            char *what() const throw()
            {
                return ((char *)"Not Enough numbers in class.");
            }
    };
};

#endif
