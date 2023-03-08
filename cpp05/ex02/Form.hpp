#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(std::string name, int gradeToSign, int gradeToExec);
		
		// Destructor
		virtual ~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		
		// Exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowExecution : public std::exception
		{
			virtual const char* what() const throw();
		};


		//Methods
		void	beSign(Bureaucrat &person);
		void	setSign(Bureaucrat &person);
		virtual void	execute (Bureaucrat const & executor) const = 0;
		bool	verifyForExecute(Bureaucrat const & executor) const;

	private:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExec;
		
};

#endif