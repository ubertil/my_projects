/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 14:03:04 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 21:58:48 2017 Lous-Emile Uberti-Ares
*/

#include "nm.h"

int	main(int ac, const char **av)
{
  int	i;
  int	nb;

  nb = 0;
  if (ac == 1)
    return (my_nm(FILE_DEFAULT, false));
  else
    {
      i = 0;
      while (++i < ac)
	if (my_nm(av[i], ((ac > 2) ? (true) : (false))) == false)
	  ++nb;
    }
  return (nb);
}
