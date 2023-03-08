#include "Intern.hpp"

//enum
enum formType
{
	e_Robot,
	e_Presi,
	e_Shrub
};

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Methods
Form* Intern::makeForm(std::string form,  std::string target)
{
	std::string const list[3] = {"robotomy request", "shrubbery creation", "presidential request"};
	Form*	(Intern::*tableForm[3])(std::string target) = {&Intern::robotomy, &Intern::shrub, &Intern::presi};

	for (int i = 0; i < 3; i++)
	{
		if (list[i] == form)
		{
			std::cout << "The Intern creates " << form << std::endl;
			return (this->*tableForm[i])(target);
		}
	}
	throw NoexistException();
}

Form*	Intern::robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form*	Intern::shrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form*	Intern::presi(std::string target)
{
	return new PresidentialPardonForm(target);
}

// Exception
const char * Intern::NoexistException::what() const throw()
{
	return ("This Form no exist the Intern is lost...");
}
// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

