#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("default_target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	checkExecution(b);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
