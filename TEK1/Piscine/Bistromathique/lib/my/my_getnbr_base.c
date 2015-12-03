/*
** my_getnbr_base.c for my_getnbr_base in /home/uberti_l/rendu/Piscine_C_J06/ex_17
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 19 20:07:16 2015 louis-emile uberti-ares
** Last update Mon Oct 19 20:18:41 2015 louis-emile uberti-ares
*/

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	rank;
  int	result;

  i = 0;
  rank = 0;
  if (str[0] == '\0')
    {
      return (0);
    }
  while (str[i] != '\0')
    {
      rank = 0;
      while (base[rank] != str[i])
	  rank = rank + 1;
      result = (result * my_strlen(base)) + rank;
      i = i + 1;
    }
  return (result);
}
