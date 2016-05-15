/*
** get_next_line.c for get_next_line.c in /home/trogno_n/rendu/CPE/CPE_2015_getnextline
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Thu Jan  7 10:51:43 2016 nicolas trognot
** Last update Thu Apr 21 11:23:59 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_concat(char *prefix, char *sufix, int which_one,
			   int ret_of_read)
{
  t_concat	concat;

  concat.len = -1;
  while (prefix[++concat.len] != '\0');
  concat.tmp = 0;
  while (sufix[concat.tmp++] != '\0');
  if ((concat.dst = malloc(concat.len + concat.tmp + 1)) == NULL)
    return (NULL);
  concat.len = -1;
  while (prefix[++concat.len] != '\0')
    concat.dst[concat.len] = prefix[concat.len];
  concat.tmp = concat.len;
  concat.len = -1;
  if (ret_of_read == 0)
    while (sufix[++concat.len] != '\0')
      concat.dst[concat.len + concat.tmp] = sufix[concat.len];
  else
    while (++concat.len < ret_of_read)
      concat.dst[concat.len + concat.tmp] = sufix[concat.len];
  concat.dst[concat.len + concat.tmp] = '\0';
  (which_one == 1) ? (free(prefix)) : (free(sufix));
  return (concat.dst);
}

char		*transfer_my_stack_to_buffer(t_gnl *gnl,
					     char *stack)
{
  char		*ret_stack;

  if (stack != NULL)
    {
      gnl->buf = my_concat(stack, gnl->buf, 2, 0);
      free(stack);
    }
  if ((ret_stack = malloc(1)) == NULL)
    return (NULL);
  ret_stack[0] = '\0';
  return (ret_stack);
}

int		check_line(t_gnl *gnl, char **stack)
{
  if (((gnl->check_add_to_stack = malloc(2)) == NULL) ||
      ((gnl->check_ret_stack = malloc(1)) == NULL))
    return (1);
  gnl->check_add_to_stack[1] = '\0';
  gnl->check_ret_stack[0] = '\0';
  gnl->check_ret = 0;
  gnl->check_i = 0;
  while (gnl->buf[gnl->check_i] != '\0')
    {
      gnl->check_add_to_stack[0] = gnl->buf[gnl->check_i];
      if (gnl->check_ret == 1)
	gnl->check_ret_stack =
	  my_concat(gnl->check_ret_stack, gnl->check_add_to_stack, 1, 0);
      if (gnl->buf[gnl->check_i] == '\n')
	gnl->check_ret = 1;
      if (gnl->check_ret == 1)
	gnl->buf[gnl->check_i] = '\0';
      gnl->check_i = gnl->check_i + 1;
    }
  free(gnl->check_add_to_stack);
  free(*stack);
  *stack = gnl->check_ret_stack;
  return (gnl->check_ret);
}

char		*get_next_line(const int fd)
{
  t_gnl		gnl;
  static char	*stack = NULL;
  static int	is_end = 0;

  if ((is_end == 1) || (READ_SIZE <= 0))
    return (NULL);
  if ((gnl.buf = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  gnl.buf[0] = '\0';
  stack = transfer_my_stack_to_buffer(&gnl, stack);
  gnl.ret = 1;
  while ((check_line(&gnl, &stack) == 0) &&
	 ((gnl.ret = read(fd, gnl.plug, READ_SIZE)) != -1))
    {
      if (gnl.ret == 0)
	return (NULL);
      gnl.plug[gnl.ret] = '\0';
      gnl.buf = my_concat(gnl.buf, gnl.plug, 1, gnl.ret);
    }
  if (gnl.ret == -1)
    return (NULL);
  if (gnl.ret == 0)
    free(stack);
  is_end = (gnl.ret == 0) ? (1) : (0);
  return (gnl.buf);
}
