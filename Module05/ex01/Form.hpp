#ifndef FORM_H
# define FORM_H

# include <iostream>

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
        virtual ~Form();

        std::string     getName()const;
        bool            getSign()const;
        unsigned int    getGradeSign()const;
        unsigned int    getGradeExec()const;
        void            beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &value);

#endif
