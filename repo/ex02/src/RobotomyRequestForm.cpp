#include "RobotomyRequestForm.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("robotomy_request_form", 72, 45),
	_target("default_target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("robotomy_request_form", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other),
	_target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	checkExecution(b);
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << GREEN << _target << " has been robotomized" << RESET << std::endl;
	else
		std::cout << RED << "robotomy failed" << RESET << std::endl;
}
