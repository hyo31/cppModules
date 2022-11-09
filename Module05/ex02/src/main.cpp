#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
	
	Bureaucrat a("Henkie", 1);
	ShrubberyCreationForm Form1("tree");
	PresidentialPardonForm Form2("Milan");
	RobotomyRequestForm Form3 ("Trasher");
	ShrubberyCreationForm Form4(Form1);
	a.executeForm(Form1);
	a.executeForm(Form4);
	a.executeForm(Form2);
	a.executeForm(Form3);
	std::cout << std::endl;
	a.signForm(Form1);
	a.signForm(Form4);
	a.signForm(Form2);
	a.signForm(Form3);
	std::cout << std::endl;
	a.executeForm(Form1);
	a.executeForm(Form4);
	a.executeForm(Form2);
	a.executeForm(Form3);
	std::cout << std::endl;
	return 0;
}
