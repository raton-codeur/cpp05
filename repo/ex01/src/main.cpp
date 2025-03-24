#include "Form.hpp"

int main()
{
	std::cout << "-- 1 --" << std::endl;
	{
		Form f1;
		std::cout << "f1 (default-constructed) : " << f1 << std::endl;
		Form f2("registration_form", 20, 30);
		std::cout << "f2 (constructed with parameters) : " << f2 << std::endl;
		Form f3(f2);
		std::cout << "f3 (copy-constructed) : " << f3 << std::endl;
		f2 = f1;
		std::cout << "f2 (assigned from b1) : " << f2 << std::endl;
	}
	std::cout << "--- 2 ---" << std::endl;
	try
	{
		Form f("registration_form", 0, 30);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f("registration_form", -5, 30);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--- 3 ---" << std::endl;
	try
	{
		Form f("registration_form", 20, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--- 4 ---" << std::endl;
	{
		Bureaucrat	b("bob", 10);
		Form		f1("admission_form", 10, 30);
		Form		f2("registration_form", 20, 30);
		f1.beSigned(b);
		f2.beSigned(b);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	std::cout << "--- 5 ---" << std::endl;
	try
	{
		Bureaucrat	b("bob", 25);
		Form		f("registration_form", 20, 30);
		f.beSigned(b);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--- 6 ---" << std::endl;
	{
		Bureaucrat	b("bob", 10);
		Form		f1("admission_form", 10, 30);
		Form		f2("registration_form", 20, 30);
		Form		f3("consent_form", 5, 30);
		b.signForm(f1);
		b.signForm(f2);
		b.signForm(f3);
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	}
}
