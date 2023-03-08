#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooLow();
	else if ( grade > 150)
		throw GradeTooHigh();
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}




// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	return *this;
}


// Getters / Setters
std::string const Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

// Methods

void	Bureaucrat::IncreasedGrade()
{
	if (this->_grade < 150)
		_grade++;
	else
		throw GradeTooHigh();
}
void	Bureaucrat::DecreasedGrade()
{
	if (this->_grade > 1)
		_grade--;
	else
		throw GradeTooLow();
}
// Exceptions
const char * Bureaucrat::GradeTooHigh::what() const throw()
{
	return "Error : grade is too High";
}
const char * Bureaucrat::GradeTooLow::what() const throw()
{
	return "Error : grade is too Low";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "Bureaucrat " << object.getName() << " grade " << object.getGrade() << "" << std::endl;
	return stream;
}
