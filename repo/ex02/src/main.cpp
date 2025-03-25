#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "--- 1 ---" << std::endl;
	ShrubberyCreationForm f;
	std::cout << f << std::endl;
	std::cout << "--- 2 ---" << std::endl;
	Bureaucrat b1("bob", 140);
	Bureaucrat b2("john", 1);
	b2.signForm(f);
	f.execute(b2);
}

