/*
** malloc.h for malloc in /Users/uberti_l/rendu/Unix/PSU_2016_malloc
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jan 27 11:17:21 2017 Louis-Emile Uberti
** Last update Sat Feb 11 15:13:43 2017 alexis papadimitriou
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <stddef.h>
# include <stdint.h>

# define HEX ("0123456789ABCDEF")
# define DEC ("0123456789")

# define HEADER_SIZE (sizeof(t_header))

# define GET_HEADER(ptr) ((void *)((t_header *)ptr - 1))
# define GET_DATA_ADR(ptr) ((void *)((t_header *)ptr + 1))

typedef struct __attribute__((packed))	s_header
{
  size_t				size;
  struct s_header			*next;
  uint8_t				free;
}					t_header;

void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					*calloc(size_t nbelems, size_t size);
void					free(void *ptr);
void					show_alloc_mem();

#endif /* !MALLOC_H_ */
