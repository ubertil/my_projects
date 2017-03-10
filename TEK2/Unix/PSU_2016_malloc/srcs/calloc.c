/*
** calloc.c for calloc in /Users/uberti_l/rendu/Unix/PSU_2016_malloc
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Jan 28 16:17:12 2017 Louis-Emile Uberti
** Last update Sat Feb 11 14:48:13 2017 alexis papadimitriou
*/

#include <string.h>
#include "malloc.h"

void		*calloc(size_t nbelems, size_t sizelem)
{
  size_t	size;
  void		*ptr;

  size = nbelems * sizelem;
  if ((ptr = malloc(size)) == NULL)
    return (NULL);
  memset(ptr, 0, size);
  return (ptr);
}
