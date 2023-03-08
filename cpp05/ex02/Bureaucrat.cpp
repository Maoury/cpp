#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooLowException();
	else if ( grade > 150)
		throw GradeTooHighException();
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


//  Operators
 Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
 {
 	Bureaucrat overload(assign);
 	return overload;
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
		throw GradeTooHighException();
}
void	Bureaucrat::DecreasedGrade()
{
	if (this->_grade > 1)
		_grade--;
	else
		throw GradeTooLowException();
}
void	Bureaucrat::signForm(Form &Form)
{
	if (_grade <= Form.getGradeToSign())
	{
		Form.setSign(*this);
		std::cout << _name << " signs " << Form.getName() << std::endl;
	}
	else
		std::cout << _name << " can't signs " << Form.getName() << " because he's under the ladder of administration" << std::endl;
}

void  Bureaucrat::executeForm (Form const & form)
{
	if (form.verifyForExecute(*this))
	{
		std::cout << _name << " execute " << form.getName() << std::endl;
		form.execute(*this);
	}
	else
	{
		std::cout << _name << " cannot be execute " << form.getName() << std::endl;  	
	}
}
// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error : grade is too High";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error : grade is too Low";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "Bureaucrat " << object.getName() << " grade " << object.getGrade() << "" << std::endl;
	return stream;
}
