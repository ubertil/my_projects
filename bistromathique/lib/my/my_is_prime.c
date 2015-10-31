/*
** my_is_prime.c for my_is_prime in /home/uberti_l/rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 12 18:40:51 2015 louis-emile uberti-ares
** Last update Mon Oct 12 21:32:48 2015 louis-emile uberti-ares
*/

int	my_is_prime(int nb)
{
  int	i;
  int	return_value;

  i = 2;
  return_value = 0;
  if ((nb == 1) || (nb == 0))
    return (0);
  while (i <= (nb / 2))
    {
      if ((nb % i) == 0)
	{
	  return_value = 1;
	  break;
	}
      i = i + 1;
    }
  if (return_value == 0)
    return (1);
  else
    return (0);
}
