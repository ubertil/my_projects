/*
** isnbr.c for isnbr in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb 19 11:33:18 2016 louis-emile uberti-ares
** Last update Thu Apr  7 11:32:57 2016 come grellard
*/

int		isnbr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9'))
	return (1);
      else
	i += 1;
    }
  return (0);
}
