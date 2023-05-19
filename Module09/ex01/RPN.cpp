#include "RNP.hpp"

RPN::RPN() {

}

RPN::~RPN() {
    while(!this->_operations.empty()) {
        this->_operations.pop();
    }
}

RPN::RPN(const RPN &copy)
{
    this->_operations = copy._operations;    
}

RPN &RPN::operator=(const RPN &copy)
{
    this->_operations = copy._operations;
    return (*this);
}

void    RPN::applyOperations(std::string input) {
    double  num;
    size_t  pos;

    for (size_t i = 0; i < input.length(); i++) {
        switch (input[i])
        {
            case '*':
                this->multiply();
                break;
            case '/':
                this->divide();
                break;
            case '+':
                this->add();
                break;
            case '-':
                this->subtract();
                break;
            case ' ':
                break;

            default:
                pos = input.find(" ", i);
                if (pos == std::string::npos) {
                    pos = input.length();
                }

                if (sscanf(input.substr(i, pos - i).c_str(), "%le", &num) != 1) {
                    std::cerr << "\033[1;31mError\033[0m" << std::endl;
                    return;
                }
                i = pos;
                
                this->_operations.push(num);


                
                break;
        }
    }
    
    std::stack<double>  copy(this->_operations);
    while (!copy.empty()) {
        std::cout << copy.top() << " ";
        copy.pop();
    }
    std::cout << std::endl;
}

void    RPN::multiply() {
    double temp;

    if (this->_operations.size() < 2)
        return;
    temp = this->_operations.top();
    this->_operations.pop();
    this->_operations.top() *= temp;
}

void    RPN::divide() {
    double temp;

    if (this->_operations.size() < 2)
        return;
    temp = this->_operations.top();
    this->_operations.pop();
    this->_operations.top() /= temp;
}

void    RPN::add() {
    double temp;

    if (this->_operations.size() < 2)
        return;
    temp = this->_operations.top();
    this->_operations.pop();
    this->_operations.top() += temp;
}

void    RPN::subtract() {
    double temp;

    if (this->_operations.size() < 2)
        return;
    temp = this->_operations.top();
    this->_operations.pop();
    this->_operations.top() -= temp;
}