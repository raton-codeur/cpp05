#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	b("bob", 1);
	Intern		i;
	std::cout << "--- 1 ---" << std::endl;
	AForm* f1 = i.makeForm("shrubbery creation", "home");
	AForm* f2 = i.makeForm("robotomy request", "john");
	AForm* f3 = i.makeForm("presidential pardon", "will");
	i.makeForm("a", "b");
	std::cout << "--- 2 ---" << std::endl;
	b.signForm(*f1);
	b.signForm(*f2);
	b.signForm(*f3);
	std::cout << "--- 3 ---" << std::endl;
	b.executeForm(*f1);
	b.executeForm(*f2);
	b.executeForm(*f3);
	delete f1;
	delete f2;
	delete f3;
}
