/*
** main.c for main in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 16 14:28:31 2017 Lous-Emile Uberti-Ares
// Last update Sun Apr  9 22:01:22 2017 Lous-Emile Uberti-Ares
*/

#include <iostream>
#include <algorithm>
#include "Error.hpp"
#include "GameManager.hh"

static inline bool	CmdOptions(char const * const *start,
				   char const * const *end,
				   const std::string &cmd)
{
  return (std::find(start, end, cmd) != end);
}

static int		usage()
{
  std::cout << "\033c" << std::endl;
  std::cout << BOLD << "NAME" << BASIC << std::endl << "\tarcade - Small arcade games for everyone" << std::endl << std::endl;
  std::cout << BOLD << "SYNOPSIS" << std::endl << "\t" << BASIC << USAGE << std::endl << std::endl;
  std::cout << BOLD << "DESCRIPTION" << BASIC << std::endl << "\tnanotekspice is an EPITECH project to develop multiple arcade games using 3 dynamic libraries" << std::endl << std::endl;
  std::cout << BOLD << "COMMAND-LINE OPTIONS" << BASIC << std::endl << std::endl;
  std::cout << BOLD << "\t-h --help" << BASIC << std::endl << "\t\tDisplays a help page and exit" << std::endl << std::endl;
  std::cout << BOLD << "AUTHORS" << BASIC << std::endl << "\tarcade was developed by a team of 2 talented developers :" << std::endl
	    << "\t- Louis-Emile UBERTI-ARES : GameManager and data architecture" << std::endl
	    << "\t- Nicolas TROGNOT : Games implementation" << std::endl << std::endl << "arcade 1.0.0 - 2017" << std::endl;
  return (0);
}

int			main(const int ac, const char * const * av)
{
  if (ac != 2)
    {
      std::cout << USAGE << std::endl;
      return (1);
    }
  else if ((CmdOptions(av, av + ac, "--help")) || (CmdOptions(av, av + ac, "-h")))
    return (usage());
  try
    {
      arcade::GameManager	manager(av[1]);
    }
  catch (const arcade::Error &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
