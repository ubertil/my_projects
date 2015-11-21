/*
** my_strcmp.c for my_strcmp in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 20:05:55 2015 louis-emile uberti-ares
** Last update Mon Oct 12 22:03:37 2015 louis-emile uberti-ares
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if ((s1[i] != s2[i]) && (s1[i] > s2[i]))
    return (1);
  if ((s1[i] != s2[i]) && (s1[i] < s2[i]))
    return (-1);
  while (s1[i] == s2[i])
    {
      i = i + 1;
      if ((s1[i] == '\0') && (s2[i] == '\0'))
	return (0);
    }
}
