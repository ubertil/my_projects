/*
** my_strcmp.c for my_strcmp in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 20:05:55 2015 louis-emile uberti-ares
** Last update Fri Jan 22 10:09:18 2016 louis-emile uberti-ares
*/

int	unstrict_cmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((s1[j] == ' ') || (s1[j] == '\t'))
    j += 1;
  if (s1[j] > s2[i])
    return (1);
  if (s1[j] < s2[i])
    return (-1);
  while (s1[j] == s2[i])
    {
      if (s2[i] == '\0')
	return (0);
      i += 1;
      j += 1;
    }
  if (s2[i] == '\0')
    return (0);
  return (2);
}
