/*
** delete.c for delete in /home/uberti_l/rendu/103architect
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Dec 10 13:49:41 2015 louis-emile uberti-ares
** Last update Thu Dec 10 16:41:44 2015 nicolas trognot
*/

#include "include/architect.h"

void		delete(t_info *info, char flag)
{
  int		i;

  switch (flag)
    {
    case 't' :
      i = 2;
      break;
    case 'r' :
      i = 1;
      break;
    case 's' :
      i = 1;
      break;
    case 'h' :
      i = 2;
      break;
    }
  while (i != 0)
    {
      info->numbers->next->next = info->numbers->next->next->next;
      i -= 1;
    }
}
