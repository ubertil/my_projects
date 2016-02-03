/*
** getnextline.c for getnextline in /home/uberti_l/rendu/Prog_elem/CPE_2015_getnextline
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jan  7 20:14:26 2016 louis-emile uberti-ares
** Last update Mon Jan 18 13:20:43 2016 louis-emile uberti-ares
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char		*my_strcpy(char *dest, char *src)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (dest[i] != '\0')
    i += 1;
  while (src[j] != '\0')
    {
      if (src[j] == '\n')
	{
	  dest[i] = '\0';
	  return (dest);
	}
      dest[i] = src[j];
      i += 1;
      j += 1;
    }
  dest[i] = '\0';
  return (dest);
}

int		find_next_line(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	return (i + 1);
      i += 1;
    }
  return (0);
}

char		*my_str_realloc(char *str, char *buffer, int idx)
{
  char		*new;

  if ((new = malloc(idx + 1)) == NULL)
    return (NULL);
  new[0] = '\0';
  new = my_strcpy(new, str);
  new = my_strcpy(new, buffer);
  free(str);
  return (new);
}

char		*clear_buffer(char *buffer)
{
  char		*new;
  int		i;
  int		j;

  if ((new = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (buffer[i] != '\n')
    i += 1;
  i += 1;
  while (buffer[i] != '\0')
    {
      new[j] = buffer[i];
      i += 1;
      j += 1;
    }
  new[j] = '\0';
  free(buffer);
  return (new);
}

char		*get_next_line(const int fd)
{
  static char	*buffer;
  int		idx;
  char		*str;

  if ((str = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  if (buffer == NULL)
    if ((buffer = malloc(READ_SIZE + 1)) == NULL)
      return (NULL);
  str[0] = '\0';
  idx = 0;
  buffer[READ_SIZE] = '\0';
  if (find_next_line(buffer) != 0)
    {
      buffer = clear_buffer(buffer);
      str = my_strcpy(str, buffer);
    }
  while (find_next_line(buffer) == 0)
    {
      if (read(fd, buffer, READ_SIZE) <= 0)
	return (str);
      idx += READ_SIZE;
      str = my_str_realloc(str, buffer, idx);
    }
  return (str);
}
