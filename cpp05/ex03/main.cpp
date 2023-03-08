#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
int    main()
{

    // try
    // {
    //  Bureaucrat f = Bureaucrat("Mamad", 40);
    //  ShrubberyCreationForm firm;
     
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // try
    // {
    //  Bureaucrat f = Bureaucrat("Mamad", 151);
    //  ShrubberyCreationForm firm;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //  Bureaucrat f = Bureaucrat("Mamad", 0);
    //  ShrubberyCreationForm firm;
    // f.signForm(firm);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    //     try
    // {
    //  Bureaucrat f = Bureaucrat("Mamad", 1);
    //          ShrubberyCreationForm firm;
    //     firm.execute(f);
    //     f.signForm(firm);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    //     try
    // {
    //  Bureaucrat f = Bureaucrat("Mamad", 1);
    //      ShrubberyCreationForm firm;

    // f.signForm(firm);
    // firm.execute(f);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    try
    {
        Bureaucrat l = Bureaucrat("lol", 2);
        Intern intern;
        Form *robot;
        Form *presi;
        Form *shrub;
        robot = intern.makeForm("robotomy request", "bender");
        presi = intern.makeForm("presidential request", "guy georges");
        shrub = intern.makeForm("shrubbery creation", "chakal");
        l.signForm(*robot);
        l.signForm(*presi);
        l.signForm(*shrub);
        robot->execute(l);
        presi->execute(l);
        shrub->execute(l);
        l.executeForm(*presi);
        delete robot;
        delete presi;
        delete shrub;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 1;
}