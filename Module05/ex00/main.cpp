#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Henkie", 2);
    Bureaucrat b("Keesie", 149);

	try
	{
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
    std::cout << a << std::endl;

	try
	{
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
    std::cout << b << std::endl;
    
	return 0;
}
