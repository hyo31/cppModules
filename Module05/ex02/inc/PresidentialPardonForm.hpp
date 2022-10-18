#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
    private:
        const std::string target;

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        virtual ~PresidentialPardonForm();

        void    action(Bureaucrat const &executor)const;
};

#endif
