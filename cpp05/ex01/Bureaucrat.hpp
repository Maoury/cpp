#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string const name, int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		std::string const getName() const;
		int getGrade() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception {
		public :
			virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
		public :
			virtual const char* what(void) const throw();
		};
		// Methods
		void	IncreasedGrade();
		void	DecreasedGrade();
		void	signForm(Form &Form);
	private:
		std::string const _name;
		int _grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif