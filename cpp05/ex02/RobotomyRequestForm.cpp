#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm()  : Form("Robotomy Request", 72, 45)
{
	_target = "";
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec())
{ 
	_target = copy.getTarget();
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, 45)
{
	_target = target;
	std::cout << "\e[0;33mFields Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	_target = assign.getTarget();
	return *this;
}


// Getters / Setters
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

// Methods
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!verifyForExecute(executor))
		throw GradeTooLowExecution();
	else
		std::cout << "Drrrr..Zzzzt *Bruit de perceuse*\n"<< getTarget() << "a été Robotomisé" << std::endl;
}