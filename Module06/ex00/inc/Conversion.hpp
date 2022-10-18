#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>

class Conversion
{
    private:
        const std::string str;
        int getInt() const;
        float getFloat() const;
        double getDouble() const;
        char getChar() const;

    public:
        Conversion(const std::string &str);
        Conversion(const Conversion &copy);
        Conversion &operator=(const Conversion &copy);
        virtual ~Conversion();

        void Print() const;
        class ImpossibleException : public std::exception
        {
	        public:
		        char *what() const throw()
                {
                    return ((char *)"Impossible.");
                }
        };
        class NonDisplayable : public std::exception
        {
	        public:
		        char *what() const throw()
                {
                    return ((char *)"Non displayable.");
                }
        };
};

#endif
