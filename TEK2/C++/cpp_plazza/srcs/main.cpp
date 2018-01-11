/*
** main.cpp for plazza in /home/login_p/delivery/plazza/main.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 10:49:24 2017 Alexis Papadimitriou
// Last update Mon Apr 24 15:59:25 2017 Lous-Emile Uberti-Ares
*/

#include <iostream>
#include "Core.hh"

int		                  main(const int ac, char const * const * av)
{
  std::unique_ptr<Plazza::Core>  core;
  std::string	                 arg;
  long		                 nb;

  if (ac != 2)
    {
      std::cout << "Usage: " << av[0] << " <nb_thread>" << std::endl;
      return (0);
    }
  arg = av[1];
  if (arg.find_first_not_of("0123456789") == std::string::npos)
    {
      nb = std::strtol(arg.c_str(), NULL, 10);
      if (nb <= 0)
      {
        std::cerr << "Error : Number of threads should be positive" << std::endl;
        return (1);
      }
      core = std::make_unique<Plazza::Core>(nb);
      core->run();
    }
  else
    std::cerr << "Error: " << arg << " is an invalid number of threads" << std::endl;
  return (0);
}