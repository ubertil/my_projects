/*
** free.c for free in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun May  7 15:20:09 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 15:25:54 2017 Lous-Emile Uberti-Ares
*/

#include "ftrace.h"

_Bool		free_list(t_list *list)
{
  t_list	*tmp;

  while ((tmp = list) != NULL)
    {
      list = list->next;
      free(tmp->name);
      free(tmp);
    }
  free(tmp);
  return (true);
}
