/*
** my_square_root.c for my_square_root in /home/uberti_l/rendu/Piscine_C_J05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  8 10:31:08 2015 louis-emile uberti-ares
** Last update Mon Oct 12 18:40:04 2015 louis-emile uberti-ares
*/

int	my_square_root(int nb)
{
  int	i;
  int	result;

  i = 1;
  result = 0;
  if ((nb < 0) || (nb > 2147483647))
    {
      return (0);
    }
  if (i < 46340)
    {
      while (result < nb)
	{
	  result = i * i;
	  if (result ==  nb)
	    {
	      return (i);
	    }
	  else
	      i = i + 1;
	}
    }
  return (0);
}
