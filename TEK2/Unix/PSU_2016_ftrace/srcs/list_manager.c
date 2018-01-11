/*
** list_manager.c for list_manager in /home/grella_c/rendu/PSU_2016_ftrace
**
** Made by Côme Grellard
** Login   <grella_c@epitech.net>
**
** Started on  Sun May  7 14:46:17 2017 Côme Grellard
** Last update Sun May  7 14:46:40 2017 Côme Grellard
*/

#include "symbol_finder.h"

int		add_node(t_list **list, const long addr, const char *name)
{
  t_list	*tmp;

  if ((tmp = malloc(sizeof(t_list))) == NULL)
    return (-1);
  tmp->addr = addr;
  if ((tmp->name = strdup(name)) == NULL)
    return (-1);
  tmp->next = *list;
  *list = tmp;
  return (0);
}
