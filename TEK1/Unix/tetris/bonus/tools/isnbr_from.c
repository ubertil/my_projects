/*
** isnbr_from.c for isnbr_from in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 23:02:01 2016 louis-emile uberti-ares
** Last update Mon Feb 22 23:17:48 2016 louis-emile uberti-ares
*/

int		isnbr_from(char *str, int i)
{
  while (str[i] != '\0')
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	i += 1;
      else
	return (1);
      if (str[i] == ',')
	return (0);
    }
  return (0);
}
