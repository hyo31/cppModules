#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->size = N;
}

Span::Span(const Span &copy)
{
    this->size = copy.size;
    this->array = copy.array;
    
}

Span &Span::operator=(const Span &copy)
{
    this->size = copy.size;
    this->array = copy.array;
        return (*this);
}

void Span::addNumber(int num)
{
    if (this->array.size() >= this->size)
        throw Span::Full();
    this->array.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    unsigned int dis = std::distance(begin, end);
    if (this->array.size() + dis > this->size)
        throw Span::Full();
    this->array.insert(this->array.end(), begin, end);
}

void Span::print() const
{
    std::vector<int> temp = this->array;
    for (std::vector<int>::iterator it = temp.begin(); it < temp.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

unsigned int Span::shortestSpan() const
{
    unsigned int        num;
    std::vector<int> temp = this->array;

    if (this->array.size() < 2)
        throw Span::NotEnough();
    std::sort(temp.begin(), temp.end());
    std::vector<int>::iterator this_it = temp.begin();
	std::vector<int>::iterator next_it = ++temp.begin();
    num = *next_it - *this_it;
    while(next_it != temp.end())
    {
        if ((*next_it - *this_it) < num)
            num = *next_it - *this_it;
        this_it++;
        next_it++;
    }
    return (num);
}

unsigned int Span::longestSpan() const
{
    std::vector<int>    temp = this->array;

    if (this->array.size() < 2)
        throw Span::NotEnough();
    std::sort(temp.begin(), temp.end());
    return (temp.back() - temp.front());
}
