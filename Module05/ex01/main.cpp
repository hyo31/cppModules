#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	a("Henkie", 2);
    Bureaucrat	b("Keesie", 149);
	Form		x("prive", 1, 1);
	Form		y("publiek", 149, 149);

	std::cout << a << std::endl;
    std::cout << b << std::endl;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
    a.signForm(x);
	a.incrementGrade();
	a.signForm(x);
	b.signForm(y);
	b.decrementGrade();
	b.signForm(y);
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	return 0;
}
