/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Fri Oct  9 16:04:05 2015 louis-emile uberti-ares
*/

int	my_printmotherfucker(int nb)
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}

int	my_put_nbr(int nb)
{
  int	modulo;
  int	spliter;

  spliter = 1;
  if ((nb < 0) && (nb != -2147483648))
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb == -2147483648)
    {
      my_printmotherfucker(nb);
    }
  while ((nb / spliter) >= 10)
    {
      spliter = spliter * 10;
    }
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter = spliter / 10;
      my_putchar(modulo + 48);
    }
}
