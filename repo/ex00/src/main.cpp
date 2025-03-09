#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- 1 ---" << std::endl;
	{
		Bureaucrat b1;
		std::cout << "b1 (default-constructed) : " << b1 << std::endl;
		Bureaucrat b2("bob", 42);
		std::cout << "b2 (constructed with parameters) : " << b2 << std::endl;
		Bureaucrat b3(b2);
		std::cout << "b3 (copy-constructed) : " << b3 << std::endl;
		b2 = b1;
		std::cout << "b2 (assigned from b1) : " << b2 << std::endl;
	}
	std::cout << "--- 2 ---" << std::endl;
	{
		try
		{
			Bureaucrat b1("bob", 0);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b1("bob", -6);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "--- 3 ---" << std::endl;
	{
		try
		{
			Bureaucrat b2("bob", 155);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
