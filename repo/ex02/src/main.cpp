#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	// RobotomyRequestForm f("john");
	// std::cout << f << std::endl;
	// Bureaucrat b("bob", 20);
	// b.signForm(f);
	// for (int i = 0; i < 10; i++)
	// 	b.executeForm(f);

	PresidentialPardonForm f("john");
	std::cout << f << std::endl;
	Bureaucrat b("bob", 5);
	b.signForm(f);
	b.executeForm(f);
}

