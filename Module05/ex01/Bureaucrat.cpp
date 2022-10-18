#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat:: GradeTooHighException();
    this->grade = grade;
    std::cout << "Bureaucrat: " << this->name << " is created, grade set to " << this->grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
    this->grade = copy.grade;
    std::cout << "Bureaucrat was copied." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    this->grade = copy.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << this->name << " died.." << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

unsigned int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << *this << " signs form " << form << std::endl;
    }
    catch (Form::GradeTooLowException &exception)
    {
        std::cout << *this << " can not sign " << form << " because: " << exception.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
    return (out);
}
