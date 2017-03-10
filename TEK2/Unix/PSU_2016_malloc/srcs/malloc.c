/*
** malloc.c for malloc in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_malloc/srcs
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Fri Jan 27 11:14:44 2017 alexis papadimitriou
** Last update Sat Feb 11 15:08:42 2017 alexis papadimitriou
*/

#include <unistd.h>
#include <pthread.h>
#include "malloc.h"

void			*first_break = 0;
pthread_mutex_t		thread_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;

static void		*get_last_block(void)
{
  t_header		*block;

  if (!first_break)
    return (NULL);
  block = first_break;
  while (block->next)
    block = block->next;
  return (block);
}

static void		*check_and_split(t_header *block, size_t size)
{
  t_header		*new_block;

  block->free = 0;
  if (block->size - size > HEADER_SIZE)
    {
      new_block = GET_DATA_ADR(block) + size;
      new_block->size = block->size - (size + HEADER_SIZE);
      new_block->free = 1;
      new_block->next = block->next;
      block->next = new_block;
      block->size = size;
    }
  return (GET_DATA_ADR(block));
}

static void		*grow_heap(void **block, size_t size,
				   size_t nb_page, size_t page_size)
{
  t_header		*last_block;
  t_header		*block_header;

  last_block = get_last_block();
  block_header = sbrk(nb_page * page_size);
  if ((long)block_header < 0)
    return (NULL);
  if (last_block)
    {
      block_header = GET_DATA_ADR(last_block) + last_block->size;
      last_block->next = block_header;
    }
  block_header->size = size;
  block_header->free = 0;
  block_header->next = NULL;
  *block = block_header;
  pthread_mutex_unlock(&thread_lock);
  return (GET_DATA_ADR(block_header));
}

static void		*refill_heap(size_t size)
{
  t_header		*block;
  t_header		*end_block;

  block = first_break;
  while (block->next)
    {
      if (block->free && block->size >= size)
	return (check_and_split(block, size));
      block = block->next;
    }
  if ((sbrk(0) - (GET_DATA_ADR(block) + block->size)) >=
      (long)(HEADER_SIZE + size))
    {
      end_block = GET_DATA_ADR(block) + block->size;
      block->next = end_block;
      end_block->size = size;
      end_block->free = 0;
      end_block->next = NULL;
      return (GET_DATA_ADR(end_block));
    }
  return (NULL);
}

void			*malloc(size_t size)
{
  size_t		nb_page;
  size_t		page_size;
  void			*block_ptr;

  pthread_mutex_lock(&thread_lock);
  if ((long)size <= 0)
    {
      pthread_mutex_unlock(&thread_lock);
      return (NULL);
    }
  page_size = getpagesize();
  nb_page = size / page_size;
  nb_page = (size - nb_page * page_size > 0) ? (nb_page + 1) : (nb_page);
  if (!first_break)
    return (grow_heap(&first_break, size, nb_page, page_size));
  else if (!(block_ptr = refill_heap(size)))
    return (grow_heap(&block_ptr, size, nb_page, page_size));
  pthread_mutex_unlock(&thread_lock);
  return (block_ptr);
}
