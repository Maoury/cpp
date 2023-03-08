#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <iostream>
# include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class Intern;

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		//Method
		Form* makeForm(std::string form, std::string target);
		Form*	robotomy(std::string target);
		Form*	shrub(std::string target);
		Form*	presi(std::string target);
		// exception
		class NoexistException : public std::exception {
		public :
			virtual const char* what(void) const throw();
		};
	private:
		
};

#endif