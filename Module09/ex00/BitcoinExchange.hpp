#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <cstdio>
# include <iomanip>

class Date
{
    public:
        int year;
        int month;
        int day;
};

class Btc
{
    private:
        std::map<std::string, long double>  _data;

    public:
        Btc(std::string dataName);
        Btc(const Btc &copy);
        Btc &operator=(const Btc &copy);
        ~Btc();
    
        void    calculateValue(std::string inputName);
        void    findCorrespondingValue (Date date, long double value);
        void    parseLine(std::string line);

    class InvalidData : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ((char *)"Bad input.");
                }
        };

};

#endif
