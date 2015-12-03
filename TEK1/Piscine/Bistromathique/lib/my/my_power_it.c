/*
** my_power_it.c for my_power_it in /home/uberti_l/rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 14:44:52 2015 louis-emile uberti-ares
** Last update Mon Oct  5 14:51:10 2015 louis-emile uberti-ares
*/

int	my_power_it(int nb, int power)
{
  int	count;
  int	result;

  count = 1;
  result = 1;
  if (power > 0)
    {
      while (count < power)
	{
	  result = result * nb;
	  count = count + 1;
	}
    }
  else
    {
      return (0);
    }
  return (result);
}
