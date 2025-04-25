#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private :
		const std::string _target;
	
	public :
								RobotomyRequestForm();
								RobotomyRequestForm(const std::string& target);
								RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
								~RobotomyRequestForm();

		void execute(const Bureaucrat& b) const;
};

#endif