/*
** IForkable.hh for plazza in /home/login_p/delivery/plazza/IForkable.hh
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Tue Apr 25 11:31:29 2017 Alexis Papadimitriou
** Last update Tue Apr 25 11:31:29 2017 Alexis Papadimitriou
*/
#pragma once

namespace Plazza
{
  namespace Process
  {
    class IForkable
    {
     public:
      virtual void run() = 0;
    };
  }
}