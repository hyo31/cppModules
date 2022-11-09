#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	
	Bureaucrat a("Henkie", 1);
	Intern x;
	Form	*rff;

	std::cout << std::endl;
	try
	{	
		rff = x.makeForm("not a form", "Robot");
		a.signForm(*rff);
		a.executeForm(*rff);
		delete (rff);
	}
	catch (Intern::unknownForm &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{	
		rff = x.makeForm("PresidentialPardonForm", "Robot");
		a.signForm(*rff);
		a.executeForm(*rff);
		delete (rff);
	}
	catch (Intern::unknownForm &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{	
		rff = x.makeForm("ShrubberyCreationForm", "Robot");
		a.signForm(*rff);
		a.executeForm(*rff);
		delete (rff);
	}
	catch (Intern::unknownForm &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

