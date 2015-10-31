/*
** my_putnbr_base.c for my_putnbr_base in /home/uberti_l/rendu/Piscine_C_J06/ex_16
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 09:32:00 2015 louis-emile uberti-ares
** Last update Mon Oct 19 20:14:33 2015 louis-emile uberti-ares
*/

int	my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  if (nbr >= my_strlen(base))
    {
      my_putnbr_base((nbr / my_strlen(base)), base);
      my_putnbr_base((nbr % my_strlen(base)), base);
    }
  else
    my_putchar(base[nbr]);
}
