/*
** my_strncmp.c for my_strncmp in /home/uberti_l/rendu/Piscine_C_J06/ex_07
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 12 21:38:44 2015 louis-emile uberti-ares
** Last update Fri Mar 18 14:34:40 2016 Louis-Emile Uberti
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i <= n)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      while ((s1[i] == s2[i]) && (i <= n))
	{
	  i += 1;
	  if (((s1[i] == '\0') && (s2[i] == '\0')) && (i == n))
	    return (0);
	  if (((s1[i] != s2[i]) && (s1[i] > s2[i])) && (i <= n))
	    return (1);
	  if (((s1[i] != s2[i]) && (s1[i] < s2[i])) && (i <= n))
	    return (-1);
	}
    }
  return (0);
}
