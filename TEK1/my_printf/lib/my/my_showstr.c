/*
** my_showstr.c for my_showstr in /home/uberti_l/rendu/Piscine_C_J07/lib/my
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 20:46:28 2015 louis-emile uberti-ares
** Last update Thu Nov 12 14:18:06 2015 louis-emile uberti-ares
*/

int	my_putnbr_base(int nbr, char *base);
void	my_putchar(char c);

int	my_showstr(char *str)
{
  int	tab[2];

  tab[0] = 0;
  tab[1] = 0;
  while (str[tab[0]] != '\0')
    {
      if ((str[tab[0]] < 32) || (str[tab[0]] > 126))
	{
	  my_putchar('\\');
	  tab[1] = tab[1] + 1;
	  if (str[tab[0]] < 14)
	    {
	      my_putchar('0');
	      tab[1] = tab[1] + 1;
	    }
	 tab[1] = my_putnbr_base(str[tab[0]], "01234567") + tab[1];
	}
      else
	{
	  my_putchar(str[tab[0]]);
	  tab[1] = tab[1] + 1;
	}
      tab[0] = tab[0] + 1;
    }
  return (tab[1]);
}
