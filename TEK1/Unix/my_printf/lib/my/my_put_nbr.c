/*
** my_put_nbr.c for my_put_nbr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:41:42 2015 louis-emile uberti-ares
** Last update Thu Nov 12 11:32:33 2015 louis-emile uberti-ares
*/

int	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);

int	my_printmotherfucker()
{
  my_putstr("-2147483648");
  return(11);
}

int	my_put_nbr(int nb)
{
  int	modulo;
  int	spliter;
  int	count;

  spliter = 1;
  count = 0;
  if ((nb < 0) && (nb != -2147483648))
    {
      my_putchar('-');
      nb = nb * -1;
      count = count + 1;
    }
  if (nb == -2147483648)
    my_printmotherfucker();
  while ((nb / spliter) >= 10)
    spliter = spliter * 10;
  while (spliter > 0)
    {
      count = count + 1;
      modulo = ((nb / spliter) %10);
      spliter = spliter / 10;
      my_putchar(modulo + 48);
    }
  return (count);
}

int	my_put_nbr_us(unsigned int nb)
{
  int	spliter;
  int	modulo;
  int	count;

  spliter = 1;
  count = 0;
  while ((nb / spliter) >= 10)
    spliter = spliter * 10;
  while (spliter > 0)
    {
      modulo = ((nb / spliter) %10);
      spliter = spliter / 10;
      count = count + 1;
      my_putchar(modulo + 48);
    }
  return (count);
}
