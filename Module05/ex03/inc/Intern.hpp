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
        std::map<std::string, Form*> Forms;
    
    public:
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        virtual ~Intern();

        Form    *makeForm(std::string typeForm, std::string nameForm);

        class unknownForm : public std::exception
        {
	        public:
		        char *what()
                {
                    return ((char *)"Unknown form.");
                }
        };

};

#endif
