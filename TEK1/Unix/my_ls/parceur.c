/*
** parceur.c for parceur in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Nov 26 10:31:10 2015 louis-emile uberti-ares
** Last update Thu Nov 26 16:43:02 2015 louis-emile uberti-ares
*/

#include "include/my.h"

void		my_display_man(void)
{
  my_putstr("\033[32;07m");
  my_putstr(LINE_A);
  my_putstr("\033[00m\n");
  my_putstr(USAGE);
  my_putstr("\033[32;04m");
  my_putstr(LINE_B);
  my_putstr("\033[00m\n");
  my_putstr(LINE_C);
  my_putstr(LINE_D);
  my_putstr(LINE_E);
  my_putstr(LINE_F);
  my_putstr(LINE_G);
}

int		find_help(int nb, char **av)
{
  int		i;
  int		k;

  i = 1;
  k = 0;
  if (nb == 1)
    return (0);
  while (i < nb)
    {
      while (av[i][k] != '\0')
	{
	  if ((av[i][k] == 'h') && (av[i][k + 1] == 'e')
		&& (av[i][k + 2] == 'l') && (av[i][k + 3] == 'p'))
	    {
	      my_display_man();
	      return (1);
	    }
	  k = k + 1;
	}
      i = i + 1;
      k = 0;
    }
  return (0);
}

int		parceur(int nb, char **av)
{
  int		i;
  int		k;

  i = 1;
  k = 0;
  if (nb == 1)
    return (0);
  while (i < nb)
    {
      while (av[i][k] != '\0')
	{
	  if ((av[i][0] == '-') &&
	      (av[i][k] != 'l') && (av[i][k] != 'd') && (av[i][k] != 'R')
	      && (av[i][k] != 'r') && (av[i][k] != 't') && (av[i][k] != '-'))
	    {
	      my_printf("my_ls: invalid option -- '%c'\n", av[i][k]);
	      my_printf("Try './my_ls --help' for more information.\n");
	      return (1);
	    }
	  k = k + 1;
	}
      i = i + 1;
      k = 0;
    }
  return (0);
}
