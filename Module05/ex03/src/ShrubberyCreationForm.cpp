#include "../inc/ShrubberyCreationForm.hpp"
#include <cstdio>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : target(target), Form("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : target(copy.target), Form(copy)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	*this = copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::remove((this->target + "_shrubbery").c_str());
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
