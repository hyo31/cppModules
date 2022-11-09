#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   name;
        unsigned int        grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, unsigned int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        virtual ~Bureaucrat();

        std::string     getName()const;
        unsigned int    getGrade()const;
        void            incrementGrade();
        void            decrementGrade();
        void            signForm(Form &form);
        void            executeForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too high!");
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value);

#endif
