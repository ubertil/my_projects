/*
** getnextline.c for getnextline in /home/uberti_l/rendu/Prog_elem/CPE_2015_getnextline
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jan  7 20:14:26 2016 louis-emile uberti-ares
** Last update Sun Jan 24 19:47:31 2016 louis-emile uberti-ares
*/

#include "../../include/mysh.h"
#include <stdlib.h>
#include <unistd.h>

char		*my_sstrcpy(char *dest, char *src)
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
  new = my_sstrcpy(new, str);
  new = my_sstrcpy(new, buffer);
  free(str);
  return (new);
}

char		*get_next_line(const int fd)
{
  char		*buffer;
  int		ret;
  int		idx;
  char		*str;

  if ((str = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  if ((buffer = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  idx = 0;
  buffer[0] = '\0';
  while (find_next_line(buffer) == 0)
    {
      if ((ret = read(fd, buffer, READ_SIZE)) <= 0)
	return (NULL);
      buffer[ret] = '\0';
      idx += READ_SIZE;
      str = my_str_realloc(str, buffer, idx);
    }
  free(buffer);
  return (str);
}
