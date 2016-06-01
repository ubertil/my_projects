/*
** is_separator.c for is_separator in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 17:06:45 2016 louis-emile uberti-ares
** Last update Thu May  5 17:42:36 2016 louis-emile uberti-ares
*/

int		is_separator(const char *sep, const char letter)
{
  int		i;

  i = -1;
  while (sep[++i] != '\0')
    if (sep[i] == letter)
      return (0);
  return (1);
}
