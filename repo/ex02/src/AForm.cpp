#include "AForm.hpp"

AForm::AForm() :
	_name("default_form"),
	_signed(false),
	_requiredGradeToSign(150),
	_requiredGradeToExecute(150)
{}

AForm::AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute) :
	_name(name),
	_signed(false),
	_requiredGradeToSign(requiredGradeToSign),
	_requiredGradeToExecute(requiredGradeToExecute)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_signed(other._signed),
	_requiredGradeToSign(other._requiredGradeToSign),
	_requiredGradeToExecute(other._requiredGradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	_signed = other._signed;
	return *this;
}

AForm::~AForm()
{}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getRequiredGradeToSign() const
{
	return _requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const
{
	return _requiredGradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "(form) grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "(form) grade too low";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return "unsigned form";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", ";
	if (f.isSigned())
		os << "signed form, ";
	else
		os << "unsigned form, ";
	os << "required grade to sign : " << f.getRequiredGradeToSign();
	os << ", required grade to execute : " << f.getRequiredGradeToExecute();
	return os;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat& b) const
{
	if (!_signed)
		throw UnsignedFormException();
	if (b.getGrade() > _requiredGradeToExecute)
		throw GradeTooLowException();
}
