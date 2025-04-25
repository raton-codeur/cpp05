#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*functions[])(const std::string& target) = {makeShrubbery, makeRobotomy, makePresidentialPardon};
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return functions[i](target);
		}
	}
	std::cout << "Intern cannot create \"" << name << "\" : invalid name" << std::endl;
	return 0;
}
