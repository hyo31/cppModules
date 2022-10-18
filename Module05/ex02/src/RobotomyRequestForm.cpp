#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : target(target), Form("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : target(copy.target), Form(copy)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    *this = copy;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action(Bureaucrat const &executor) const
{
    try
    {
        this->execute(executor);
        srand(time(NULL));
        if (!(rand() % 2))
            std::cout << this->target << " has been robotomized." << std::endl;
        else
            std::cout << "Robotomy failed." << std::endl;
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
