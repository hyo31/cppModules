#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        const std::string target;

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();

        void    action(Bureaucrat const &executor)const;
};

#endif
