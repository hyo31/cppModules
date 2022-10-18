#include "../inc/Conversion.hpp"

Conversion::Conversion(const std::string &str) : str(str)
{
}

Conversion::Conversion(const Conversion &copy) : str(copy.str)
{
}

Conversion &Conversion::operator=(const Conversion &copy)
{
    return (*this);
}

Conversion::~Conversion()
{
}

char Conversion::getChar() const
{
    int num;
    try
    {
        num = std::stoi(this->str);
        if(num < 0 || num > 255)
            throw Conversion::ImpossibleException();
    }
    catch(...)
    {
        if (!this->str[1])
            return (this->str[0]);
        throw Conversion::ImpossibleException();
    }
    if(!isprint(num))
        throw Conversion::NonDisplayable();
    return (num);
}

int Conversion::getInt() const
{
    int num;
    try
    {
        num = std::stoi(this->str);
    }
    catch(...)
    {
        throw Conversion::ImpossibleException();
    }
    return (num);
}

float Conversion::getFloat() const
{
    float num;
    try
    {
        num = std::stof(this->str);
    }
    catch(...)
    {
        throw Conversion::ImpossibleException();
    }
    return (num);
}

double Conversion::getDouble() const
{
    double num;
    try
    {
        num = std::stod(this->str);
    }
    catch(...)
    {
        throw Conversion::ImpossibleException();
    }
    return (num);
}

void Conversion::Print() const
{
    std::cout << "Char: ";
    try
    {
        this->getChar();
        std::cout << "'" << this->getChar() << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Int: ";
    try
    {
        typedef std::numeric_limits< int>num;
        std::cout.precision(num::max_digits10-2);
        std::cout << this->getInt() << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "Float: ";
    try
    {
        typedef std::numeric_limits< float> flt;
        std::cout.precision(flt::max_digits10-2);
        float num = this->getFloat();
        std::cout << num;
        if (num - (int)num == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Double: ";
    try
    {
        typedef std::numeric_limits< double> dbl;
        std::cout.precision(dbl::max_digits10-2);
        std::cout << this->getDouble() << std::endl;
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}
