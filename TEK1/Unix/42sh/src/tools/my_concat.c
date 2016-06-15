/*
** my_concat.c for my_concat in /home/grella_c/rendu/PSU_2015_42sh
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Fri Jun  3 14:07:26 2016 come grellard
** Last update Fri Jun  3 14:25:29 2016 come grellard
*/

#include <string.h>
#include <stdlib.h>

static int	get_total_len(const int mem, char **args)
{
  int		len;
  int		i;

  len = 0;
  i = mem;
  while (args[i] != NULL)
    {
      if (i > mem)
	len += 1;
      len += strlen(args[i]);
      i += 1;
    }
  return (len);
}

char		*my_concat(const int mem, char **args)
{
  char		*str;
  int		len;
  int		i;

  len = get_total_len(mem, args);
  i = mem;
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (args[i] != NULL)
    {
      if ((i > mem) && ((str = strcat(str, " ")) == NULL))
	return (NULL);
      if ((str = strcat(str, args[i])) == NULL)
	return (NULL);
      i += 1;
    }
  return (str);
}
