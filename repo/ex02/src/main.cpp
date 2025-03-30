#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	ShrubberyCreationForm	f1("home");
	RobotomyRequestForm		f2("john");
	PresidentialPardonForm	f3("bob");
	Bureaucrat				b1("david", 150);
	Bureaucrat				b2("michael", 1);

	std::cout << "--- 1 ---" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << "--- 2 ---" << std::endl;
	try
	{
		f1.execute(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b2.executeForm(f1);
	try
	{
		f2.execute(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b2.executeForm(f2);
	try
	{
		f3.execute(b2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b2.executeForm(f3);
	std::cout << "--- 3 ---" << std::endl;
	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);
	std::cout << "--- 4 ---" << std::endl;
	try
	{
		f1.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	b1.executeForm(f1);
	std::cout << "--- 5 ---" << std::endl;
	b2.executeForm(f1);
	std::cout << "--- 6 ---" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		b2.executeForm(f2);
	}
	std::cout << "--- 7 ---" << std::endl;
	b2.executeForm(f3);
}
