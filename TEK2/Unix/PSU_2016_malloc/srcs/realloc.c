/*
** realloc.c for realloc in /Users/uberti_l/rendu/Unix/PSU_2016_malloc
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jan 27 13:29:26 2017 Louis-Emile Uberti
** Last update Sat Feb 11 14:49:22 2017 alexis papadimitriou
*/

#include <string.h>
#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_header	*block;
  void		*new;
  size_t	old_size;

  if (ptr == NULL)
    return (malloc(size));
  block = GET_HEADER(ptr);
  if (block->size >= size)
    return (ptr);
  if ((new = malloc(size)) == NULL)
    return (NULL);
  old_size = ((t_header *)GET_HEADER(ptr))->size;
  memcpy(new, ptr, old_size);
  free(ptr);
  return (new);
}
