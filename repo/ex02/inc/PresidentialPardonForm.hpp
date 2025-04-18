#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		const std::string _target;

	public :
								PresidentialPardonForm();
								PresidentialPardonForm(const std::string& target);
								PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
								~PresidentialPardonForm();

		void execute(const Bureaucrat& b) const;
};

#endif