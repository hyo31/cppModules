#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 value;
        static const int    bits = 8;
    
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &copy);

        bool operator>(Fixed const &copy) const;
	    bool operator<(Fixed const &copy) const;
	    bool operator>=(Fixed const &copy) const;
	    bool operator<=(Fixed const &copy) const;
	    bool operator==(Fixed const &copy) const;
	    bool operator!=(Fixed const &copy) const;

        Fixed operator+(Fixed const &copy);
        Fixed operator-(Fixed const &copy);
        Fixed operator*(Fixed const &copy);
        Fixed operator/(Fixed const &copy);

        Fixed operator++(int);
	    Fixed operator++();
	    Fixed operator--(int);
	    Fixed operator--();

        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
Fixed const &min(Fixed const &a, Fixed const &b);
Fixed &min(Fixed &a, Fixed &b);
Fixed const &max(Fixed const &a, Fixed const &b);
Fixed &max(Fixed &a, Fixed &b);
#endif