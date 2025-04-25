#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
	public :
				Intern();
				Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
				~Intern();

		static AForm*	makeShrubbery(const std::string& target);
		static AForm*	makeRobotomy(const std::string& target);
		static AForm*	makePresidentialPardon(const std::string& target);
		AForm*			makeForm(const std::string& name, const std::string& target) const;
};

#endif