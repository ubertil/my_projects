/*
** get_all_moves.c for get_all_moves in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr 21 21:49:03 2016 louis-emile uberti-ares
** Last update Fri Apr 22 16:52:11 2016 louis-emile uberti-ares
*/

#include "visu.h"

char		*get_next_room(char *str)
{
  char		*s1;
  int		i;
  int		j;

  i = 0;
  while (str[i] != '-')
    ++i;
  j = i;
  while (str[i] != '\0')
    ++i;
  if ((s1 = malloc(sizeof(char) * (i - j))) == NULL)
    return (NULL);
  i = j;
  j = 0;
  while (str[++i] != '\0')
    s1[j++] = str[i];
  s1[j] = '\0';
  return (s1);
}
