/*
** my_getnbr.c for getnbr in /home/grella_c/rendu/Piscine_C_J04
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Mon Oct 12 17:34:59 2015 come grellard
** Last update Tue May 31 13:34:31 2016 come grellard
*/

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	nb;

  i = 0;
  neg = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	neg = neg + 1;
      if (str[i] >= '0' && str[i] <= '9')
	{
	  while (str[i] >= '0' && str[i] <= '9')
	    nb = (str[i++] - 48) + (nb * 10);
	  if ((neg % 2) == 0)
	    return (nb);
	  else
	    return (nb * (-1));
	}
      i += 1;
    }
  return (-1);
}
