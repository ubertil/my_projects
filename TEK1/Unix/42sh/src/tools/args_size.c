/*
** args_size.c for args_size in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 11:07:27 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:23:49 2016 louis-emile uberti-ares
*/

#include <stdlib.h>

int	args_size(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i])
    ++i;
  return (i);
}
