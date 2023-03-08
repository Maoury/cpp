#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubberry Creation", 145, 137)
{
	_target = "Target";
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec())
{
	_target = copy.getTarget();
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubberry Creation", 145, 137), _target(target)
{
	std::cout << "\e[0;33mFields Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	_target = assign.getTarget();
	return *this;
}

// Getters / Setters
std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

// Methods

void	ShrubberyCreationForm::execute(Bureaucrat const&  executor) const
{
	std::ofstream	file;
	std::string		nameFile;
	
	if (!verifyForExecute(executor))
		throw GradeTooLowExecution();
	else
	{
		nameFile = getTarget() + "_shrubbery";
		file.open(nameFile, std::fstream::trunc) ;
		file << "      /\\   \n     /\\*\\     \n    /\\o\\*\\    \n   /*/\\/\\/\\   \n  /\\o\\/\\*\\/\\  \n /\\*\\/\\*\\/\\/\\ \n/\\O\\/\\/*\\/o/\\\n      ||      \n      ||      \n      ||      " << std::endl;
		file.close();
		std::cout << _target << " a été shruberisé dans le repoertoire actuel" << std::endl;
	}
}