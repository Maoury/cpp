#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm ", 25, 5), _target("target")
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec())
{
	_target = copy.getTarget();
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  Form("PresidentialPardonForm ", 25, 5), _target(target)
{
	std::cout << "\e[0;33mFields Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	_target = assign.getTarget();
	return *this;
}


// Getters / Setters
std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

// Methods

void PresidentialPardonForm::execute(Bureaucrat const&  executor) const
{
	if (!verifyForExecute(executor))
		throw GradeTooLowExecution();
	else
		std::cout << getTarget() << "a été pardonné(e) par Zafod Beeblebrox" << std::endl;
}