#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
	private :
		const std::string	_name;
		bool				_signed;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExecute;
	public :
							Form();
							Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute);
							Form(const Form& other);
		Form&				operator=(const Form& other);
							~Form();
		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGradeToSign() const;
		int					getRequiredGradeToExecute() const;
		void				beSigned(const Bureaucrat& b);

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif