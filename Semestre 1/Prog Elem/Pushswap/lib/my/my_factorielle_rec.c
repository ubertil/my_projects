/*
** my_factorielle_rec.c for my_factorielle_rec in /rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  2 11:21:18 2015 louis-emile uberti-ares
** Last update Tue Oct  6 14:29:31 2015 louis-emile uberti-ares
*/

int	my_factorielle_rec(int nb)
{
  int	result;

  if ((nb > 12) || (nb < 0))
    {
      return (0);
    }
  if ((nb == 0) || (nb == 1))
    {
      return (1);
    }
  else
    {
      result = nb * my_factorielle_rec(nb - 1);
      return (result);
    }
}
