#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy), target(copy.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
    (void)copy;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::action(Bureaucrat const &executor) const
{
    try
    {
        this->execute(executor);
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    catch (Form::FormNotSignedException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}
