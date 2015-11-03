/*
** my_find_prime_sup.c for my_find_is_sup in /home/uberti_l/rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 12 20:52:59 2015 louis-emile uberti-ares
** Last update Mon Oct 12 21:30:48 2015 louis-emile uberti-ares
*/

int	my_find_prime_sup(int nb)
{
  int	i;
  int	return_value;

  i = 2;
  return_value = 0;
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
    return (nb);
  else
    {
      nb = nb + 1;
      my_find_prime_sup(nb);
    }
}
