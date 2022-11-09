#include "../inc/ShrubberyCreationForm.hpp"
#include <cstdio>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy), target(copy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action(Bureaucrat const &executor) const
{
	try
	{
		this->execute(executor);
		std::ofstream outfile;
		outfile.open(this->target + "_shrubbery");
		if (outfile.is_open() == false)
			throw std::ofstream::failure("Could not open file " + this->target + "_shrubbery");
		std::cout << this->target + "_shrubbery has been created." <<std::endl;
		outfile << " TREES ";
		outfile.close();
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
