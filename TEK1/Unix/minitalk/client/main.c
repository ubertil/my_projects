/*
** main.c for main_client in /home/uberti_l/rendu/Unix/PSU_2015_minitalk/client
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  1 11:40:27 2016 louis-emile uberti-ares
** Last update Tue Feb  2 16:13:19 2016 louis-emile uberti-ares
*/

#include "include/client.h"
#include <stdlib.h>

int		check_pid(char **av)
{
  int		i;

  i = 0;
  if (av[1][0] == '\0')
    {
      my_putstr_err("Error : (null)");
      my_putstr_err(" is not a valid PID\nAborting\n");
      return (1);
    }
  while (av[1][i] != '\0')
    {
      if ((av[1][i] >= '0') && (av[1][i] <= '9'))
	i += 1;
      else
	{
	  my_putstr_err("Error : ");
	  my_putstr_err(av[1]);
	  my_putstr_err(" is not a valid PID\nAborting\n");
	  return (1);
	}
    }
  return (my_getnbr(av[1]));
}

int		main(int ac, char **av)
{
  int		pid;

  if (ac != 3)
    {
      my_putstr_err("Usage : ./client [SERVER PID] [MESSAGE]\n");
      return (0);
    }
  else
    {
      if ((pid = check_pid(av)) == 1)
	return (0);
    }
  ascii_to_binary(av[2], pid);
  return (0);
}
