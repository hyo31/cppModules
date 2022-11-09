#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy), target(copy.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    (void)copy;
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
