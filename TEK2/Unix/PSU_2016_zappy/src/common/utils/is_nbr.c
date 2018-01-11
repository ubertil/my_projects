/*
** is_nbr.c for is_nbr in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 21 13:43:03 2017 Lous-Emile Uberti-Ares
** Last update Wed Jun 21 14:26:28 2017 Lous-Emile Uberti-Ares
*/

#include <ctype.h>
#include "common/utils/utils.h"

INLINE bool	is_nbr(const char *str)
{
  int		i;

  i = -1;
  if (!str)
    return (false);
  while (str[++i] != '\0')
    if (!isdigit(str[i]))
      return (false);
  return (true);
}
