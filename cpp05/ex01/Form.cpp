# include "Form.hpp"
# include "Bureaucrat.hpp"
// Constructors
Form::Form() : _name("Default")
{
	_signed			= 0;
	_gradeToSign	= 150;
	_gradeToExec	= 150;
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName())
{
	_signed			= copy.getSigned();
	_gradeToSign	= copy.getGradeToSign();
	_gradeToExec 	= copy.getGradeToExec();
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
// Form & Form::operator=(const Form &assign)
// {
// 	_signed = assign.getSigned();
// 	_gradeToSign = assign.getGradeToSign();
// 	_gradeToExec = assign.getGradeToExec();
// 	return *this;
// }


// Getters / Setters
std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
int Form::getGradeToSign() const
{
	return _gradeToSign;
}
int Form::getGradeToExec() const
{
	return _gradeToExec;
}
void	Form::setSign(Bureaucrat &person)
{
		if (_gradeToSign >= person.getGrade())
			_signed = 1;
}
// Methods
void	Form::beSign(Bureaucrat &person)
{
	if (_gradeToSign >= person.getGrade())
	{
		_signed = 1;
		std::cout << _name << " Form is signed by " << person.getName() << std::endl; 
	}
	else
	{
		// std::cout << _name << " Form is signed by " << Bureaucrat.getName(); 
		throw GradeTooLowException();
	}
}
// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}
