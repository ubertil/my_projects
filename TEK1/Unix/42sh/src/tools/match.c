/*
** match.c for 42sh in /home/papadi_a/work/epitech/PSU/PSU_2015_42sh
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Fri Jun  3 12:02:31 2016 alexis papadimitriou
** Last update Sun Jun  5 16:26:54 2016 louis-emile uberti-ares
*/

int	match(char *s1, char *s2)
{
  if (!*s1 && !*s2)
    return (1);
  if (*s1 == *s2 && *s1 && *s2)
    return (match(s1 + 1, s2 + 1));
  if (!*s1 && *s2 == '*')
    return (match(s1, s2 + 1));
  if (*s1 && *s2 == '*')
    return (match(s1 + 1, s2) || match(s1, s2 + 1));
  return (0);
}
