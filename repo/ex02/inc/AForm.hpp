#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExecute;

	public :
				AForm();
				AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
				AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual	~AForm() = 0;

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGradeToSign() const;
		int					getRequiredGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

		virtual void execute(const Bureaucrat& b) const;

		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class UnsignedFormException : public std::exception
		{
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif