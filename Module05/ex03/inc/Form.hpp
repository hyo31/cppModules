#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <fstream>

class Bureaucrat;

class   Form
{
    private:
        const std::string   name;
        bool                sign;
        const unsigned int  gradeSign;
        const unsigned int  gradeExec;
        Form() : name("<name>"), gradeSign(150), gradeExec(150){};

    public:
        Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExec);
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        virtual ~Form() = 0;

        std::string     getName()const;
        bool            getSign()const;
        unsigned int    getGradeSign()const;
        unsigned int    getGradeExec()const;
        void            beSigned(const Bureaucrat &bureaucrat);
        void            execute(Bureaucrat const &executor)const;

        virtual void action(Bureaucrat const &executor) const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form is not signed!");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif
