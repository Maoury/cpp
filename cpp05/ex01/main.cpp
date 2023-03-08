#include "Form.hpp"

int    main()
{
   try
   {
        Bureaucrat f = Bureaucrat("Mamad", 40);
        // Bureaucrat chak = Bureaucrat("LOli", 151);
        // Bureaucrat pas("Mark", 0);
        Form form = Form("form", 50, 50);
        Form firm = Form("Acte de Notoriété", 50, 50);

        form.beSign(f);
        f.signForm(firm);
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
    try
    {
    Bureaucrat f = Bureaucrat("Mamad", 40);
    Form firm = Form("Acte de Notoriété", 50, 50);
    f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
     Bureaucrat f = Bureaucrat("Mamad", 40);
     Form firm = Form("Acte de Notoriété", 20, 50);
     f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
     Bureaucrat f = Bureaucrat("Mamad", 151);
     Form firm = Form("Acte de Notoriété", 20, 50);
     f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
     Bureaucrat f = Bureaucrat("Mamad", 0);
     Form firm = Form("Acte de Notoriété", 20, 50);
     f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
     Bureaucrat f = Bureaucrat("Mamad", 40);
     Form firm = Form("Acte de Notoriété", 0, 50);
     f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
     Bureaucrat f = Bureaucrat("Mamad", 40);
     Form firm = Form("Acte de Notoriété", 151, 50);
     f.signForm(firm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 1;
}