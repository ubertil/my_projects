/*
** my_factorielle_it.c for my_factorielle_it in /rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  2 09:50:22 2015 louis-emile uberti-ares
** Last update Tue Oct  6 14:27:53 2015 louis-emile uberti-ares
*/

int	my_factorielle_int(int nb)
{
  int	i;
  int	result;

  i = nb - 1;
  result = nb;
  if ((nb >= 12) || (nb <= 0))
    {
      return (0);
    }
  if (nb == 0)
    {
      return (1);
    }
    while (i > 1)
      {
	result = result * i;
	i = i - 1;
      }
    return (result);
}
