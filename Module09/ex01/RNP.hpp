#ifndef RNP_HPP
# define RNP_HPP

# include <iostream>
# include <stack>
# include <string>
# include <cstdio>
# include <iomanip>

class RPN
{
    private:
        std::stack<double>  _operations;
        void    multiply();
        void    divide();
        void    add();
        void    subtract();

    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        void    applyOperations(std::string input);
};

#endif