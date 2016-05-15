/*
** my_getnbr.c for getnbr in /home/grella_c/rendu/Piscine_C_J04
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Mon Oct 12 17:34:59 2015 come grellard
** Last update Sat Apr 23 17:05:28 2016 come grellard
*/

int	my_getnbr(char *str)
{
  int	i;
  int	moins;
  int	nbr;

  i = -1;
  moins = 0;
  nbr = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == '-')
	  moins = moins + 1;
      if (str[i] >= '0' && str[i] <= '9')
	{
	  while (str[i] >= '0' && str[i] <= '9')
	    {
	      nbr = str[i] - 48 + nbr * 10;
	      i = i + 1;
	    }
	  if ((moins % 2) == 0)
	    return (nbr);
	  else
	    return (nbr * (-1));
	}
    }
  return (-1);
}
