#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("shrubbery_creation_form", 145, 137),
	_target("default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("shrubbery_creation_form", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	checkExecution(b);
	std::cout << "exec du shruberry par " << b << std::endl;
}
