/*
** main.c for objdump in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 14:15:52 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 21:57:47 2017 Lous-Emile Uberti-Ares
*/

#include "objdump.h"
#include "common.h"

int	main(int ac, const char **av)
{
  int	i;
  int	error;

  i = 0;
  error = 0;
  if (ac < 2)
    return (my_objdump(FILE_DEFAULT));
  else
    {
      while (++i < ac)
	if (my_objdump(av[i]) == false)
	  ++error;
    }
  return (error);
}
