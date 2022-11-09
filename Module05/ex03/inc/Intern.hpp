#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <map>

class Intern
{
    private:
        Form *Forms[3];
    
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        virtual ~Intern();

        Form    *makeForm(std::string typeForm, std::string nameForm);

        class unknownForm : public std::exception
        {
	        public:
		        virtual const char *what() const throw()
                {
                    return ("Unknown form.");
                }
        };

};

#endif
