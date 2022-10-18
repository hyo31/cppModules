#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include <random>

class RobotomyRequestForm : public Form
{
    private:
        const std::string target;

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();

        void    action(Bureaucrat const &executor)const;
};

#endif
