#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm f;
	std::cout << f << std::endl;
	Bureaucrat b("bob", 20);
	b.signForm(f);
	b.executeForm(f);
}

