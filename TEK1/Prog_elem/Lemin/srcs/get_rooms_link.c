/*
** get_rooms_link.c for get_rooms_link in /home/grella_c/rendu/CPE_2015_Lemin/srcs
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Fri Apr 15 11:54:54 2016 come grellard
** Last update Fri Apr 15 12:13:13 2016 come grellard
*/

#include <stdlib.h>

int	check_link(char *str)
{
  int	i;
  int	nb_tiret;

  i = 0;
  nb_tiret = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	nb_tiret += 1;
      i += 1;
    }
  if (nb_tiret != 1)
    return (1);
  return (0);
}

char	*get_first_room(char *str)
{
  char	*s1;
  int	i;

  i = 0;
  while (str[i] != '-')
    i += 1;
  if ((s1 = malloc(i + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] != '-')
    s1[i] = str[i];
  s1[i] = '\0';
  return (s1);
}

char	*get_second_room(char *str)
{
  char	*s2;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '-')
    i += 1;
  i += 1;
  while (str[i++] != '\0')
    j += 1;
  if ((s2 = malloc(j + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] != '-')
    i += 1;
  i += 1;
  while (str[i] != '\0')
    s2[j++] = str[i++];
  s2[j] = '\0';
  return (s2);
}
