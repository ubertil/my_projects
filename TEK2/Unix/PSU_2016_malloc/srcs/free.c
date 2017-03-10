/*
** free.c for free in /Users/uberti_l/rendu/Unix/PSU_2016_malloc
1;4601;0c**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jan 27 13:37:31 2017 Louis-Emile Uberti
** Last update Sat Feb 11 15:04:58 2017 alexis papadimitriou
*/

#include <pthread.h>
#include "malloc.h"

extern pthread_mutex_t	thread_lock;

void			check_and_merge(t_header *block)
{
  t_header		*to_merge;

  block->free = 1;
  if (block->next && block->next->free)
    {
      to_merge = block->next;
      block->next = to_merge->next;
      block->size = block->size + HEADER_SIZE + to_merge->size;
    }
}

void			free(void *ptr)
{
  t_header		*block;

  pthread_mutex_lock(&thread_lock);
  if (!ptr)
    {
      pthread_mutex_unlock(&thread_lock);
      return ;
    }
  block = GET_HEADER(ptr);
  check_and_merge(block);
  pthread_mutex_unlock(&thread_lock);
}
