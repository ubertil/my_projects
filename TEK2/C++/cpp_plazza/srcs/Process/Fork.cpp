/*
** Fork.cpp for plazza in /home/login_p/delivery/plazza/Fork.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue Apr 25 11:38:33 2017 Alexis Papadimitriou
** Last update Tue Apr 25 11:38:33 2017 Alexis Papadimitriou
*/

#include <stdexcept>
#include <cstdlib>
#include "Process/Fork.hh"

Plazza::Process::Fork::Fork(IForkable &forkable) :
  _forkable(forkable)
{
}

pid_t Plazza::Process::Fork::launch()
{
  pid_t pid;

  if ((pid = fork()) == -1)
    throw std::runtime_error("Failed to fork");
  else if (not pid)
    {
      this->_forkable.run();
      std::exit(EXIT_SUCCESS);
    }
  return (pid);
}