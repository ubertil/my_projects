/*
** my_power_rec.c for my_power_rec in /home/uberti_l/rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 14:51:19 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:17:34 2015 louis-emile uberti-ares
*/

int	my_power_rec(int nb, int power)
{
  int	result;

  if (power > 0)
    {
      result = nb * my_power_rec(nb, (power - 1));
      return(result);
    }
  else
    {
      if (power == 0)
	{
	  return (1);
	}
      return (0);
    }
}
