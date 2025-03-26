#include "Form.hpp"

Form::Form() :
	_name("default_form"),
	_signed(false),
	_requiredGradeToSign(150),
	_requiredGradeToExecute(150)
{}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute) :
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

Form::Form(const Form& other) :
	_name(other._name),
	_signed(other._signed),
	_requiredGradeToSign(other._requiredGradeToSign),
	_requiredGradeToExecute(other._requiredGradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	_signed = other._signed;
	return *this;
}

Form::~Form()
{}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getRequiredGradeToSign() const
{
	return _requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const
{
	return _requiredGradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "(form) grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "(form) grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
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

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
