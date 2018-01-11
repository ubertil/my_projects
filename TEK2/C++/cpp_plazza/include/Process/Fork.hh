/*
** Fork.hh for plazza in /home/login_p/delivery/plazza/Fork.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue Apr 25 11:23:54 2017 Alexis Papadimitriou
** Last update Tue Apr 25 11:23:54 2017 Alexis Papadimitriou
*/
#pragma once
# include <unistd.h>
# include "IForkable.hh"

namespace Plazza
{
  namespace Process
  {
    class Fork
    {
     private:
      IForkable &_forkable;
     public:
      Fork(IForkable &forkable);
      Fork(const Fork &cpy) = delete;
      ~Fork() = default;

      Fork &operator=(const Fork &cpy) = delete;

      pid_t launch();
    };
  }
}