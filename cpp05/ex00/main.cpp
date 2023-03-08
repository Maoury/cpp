#include "Bureaucrat.hpp"

int    main()
{
   try
   {
        Bureaucrat f = Bureaucrat("Mamad", 56);
        Bureaucrat chak = Bureaucrat("LOli", 151);
        Bureaucrat pas("Mark", 0);
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
   
  
return 1;

}