#include "../inc/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
}

Intern &Intern::operator=(Intern const &copy)
{
    return (*this);
}

Intern::~Intern()
{
	delete Forms["robotomy request"];
	delete Forms["presidential pardon"];
	delete Forms["shrubbery creation"];
}

Form    *Intern::makeForm(std::string typeForm, std::string nameForm)
{
	Forms.insert(std::make_pair("robotomy request", new RobotomyRequestForm(nameForm)));
	Forms.insert(std::make_pair("presidential pardon", new PresidentialPardonForm(nameForm)));
	Forms.insert(std::make_pair("shrubbery creation", new ShrubberyCreationForm(nameForm)));
	std::cout << "Attempting to create form: " << typeForm << "." << std::endl;
	if (Forms.find(typeForm) == Forms.end())
		throw unknownForm();
	return (Forms[typeForm]);
}
