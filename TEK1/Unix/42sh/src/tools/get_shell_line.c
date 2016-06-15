/*
** getnextline.c for getnextline in /home/uberti_l/rendu/Prog_elem/CPE_2015_getnextline
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Jan  7 20:14:26 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:24:21 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "tools.h"

static char	*my_cpy(char *dest, const char *src)
{
  int		i;
  int		j;

  j = -1;
  i = 0;
  while (dest[i] != '\0')
    ++i;
  while (src[++j] != '\0')
    {
      dest[i] = src[j];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

static char		*my_str_realloc(char *str, char **buffer)
{
  char			*new;

  if ((new = malloc(strlen(str) + 2)) == NULL)
    return (NULL);
  new[0] = '\0';
  new = my_cpy(new, str);
  new = my_cpy(new, *buffer);
  free(str);
  return (new);
}

char		*get_shell_line(const int fd)
{
  char		*buffer;
  char		*str;

  if (((str = malloc(2)) == NULL) ||
      ((buffer = malloc(2)) == NULL))
    return (NULL);
  buffer[0] = '\0';
  str[0] = '\0';
  while (read(fd, buffer, 1) > 0)
    {
      buffer[1] = '\0';
      if ((str = my_str_realloc(str, &buffer)) == NULL)
	return (NULL);
      if (buffer[0] == '\n' || buffer[0] == '\0')
	{
	  str[strlen(str) - 1] = '\0';
	  free(buffer);
	  return (str);
	}
    }
  free(buffer);
  return ((str[0] != '\0') ? (str) : (NULL));
}
