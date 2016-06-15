/*
** is_space.c for is_space in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun  1 15:17:11 2016 louis-emile uberti-ares
** Last update Wed Jun  1 15:17:59 2016 louis-emile uberti-ares
*/

int	is_space(const char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] != ' ' && str[i] != '\t')
      return (0);
  return (1);
}
