#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string   name;
        unsigned int        grade;
    
        Bureaucrat() : name("<name>"), grade(150){};

    public:
        Bureaucrat(const std::string &name, unsigned int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        virtual ~Bureaucrat();

        std::string     getName()const;
        unsigned int    getGrade()const;
        void            incrementGrade();
        void            decrementGrade();
        void            signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                char *what()
                {
                    return ((char *)"Grade too high!");
                }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                char *what()
                {
                    return ((char *)"Grade too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value);

#endif
