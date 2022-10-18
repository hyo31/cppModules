#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Bureaucrat:: GradeTooLowException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Bureaucrat:: GradeTooHighException();
    this->sign = false;
    std::cout << "Form: " << this->name << " was created." << std::endl;
}

Form::Form(const Form &copy) : name(copy.getName()), gradeSign(copy.getGradeSign()), gradeExec(copy.getGradeExec())
{
    this->sign = copy.sign;
    std::cout << "Form was copied." << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    this->sign = copy.sign;
    return (*this);
}

Form::~Form()
{
    std::cout << this->name << " was deleted.." << std::endl;
}

std::string Form::getName() const
{
    return(this->name);
}

bool    Form::getSign() const
{
    return(this->sign);
}

unsigned int Form::getGradeSign() const
{
    return(this->gradeSign);
}

unsigned int Form::getGradeExec() const
{
    return(this->gradeExec);
}

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
    this->sign = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << form.getName() << ", signGrade: " << form.getGradeSign() << ", execGrade: " << form.getGradeExec();
    if (form.getSign())
        out << ", form is signed.";
    else
        out << ", form is not signed";
    return (out);
}
