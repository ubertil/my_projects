/*
** my_getnbr.c for getnbr in /home/grella_c/rendu/Piscine_C_J04
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Mon Oct 12 17:34:59 2015 come grellard
** Last update Wed Apr  6 16:52:51 2016 come grellard
*/

int	check(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '-')
    i += 1;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i += 1;
      else
	return (-1);
    }
  return (0);
}

int	my_hard_getnbr(char *str)
{
  int	i;
  int	moins;
  int	nbr;

  i = 0;
  moins = 0;
  nbr = 0;
  if (check(str) == -1)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	  moins = moins + 1;
      if (str[i] >= '0' && str[i] <= '9')
	{
	  while (str[i] >= '0' && str[i] <= '9')
	    nbr = str[i++] - 48 + nbr * 10;
	  if ((moins % 2) == 0)
	    return (nbr);
	  else
	    return (nbr * (-1));
	}
      i = i + 1;
    }
  return (-1);
}
