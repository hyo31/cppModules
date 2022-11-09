#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(Intern const &copy)
{
	(void)copy;
    return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern died..." << std::endl;
}

Form    *Intern::makeForm(std::string typeForm, std::string nameForm)
{
	int ret = -1;
	Forms[0] = new ShrubberyCreationForm(nameForm);
	Forms[1] = new RobotomyRequestForm(nameForm);
	Forms[2] = new PresidentialPardonForm(nameForm);
	for (int i = 0; i < 3; i++)
	{
		if (typeForm == Forms[i]->getName())
			ret = i;
		else
			delete (Forms[i]);
	}
	if (ret == -1)
		throw unknownForm();
	return (Forms[ret]);
}
