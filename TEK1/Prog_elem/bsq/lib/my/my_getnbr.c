/*
** my_getnbr.c for my_getnbr in /home/uberti_l/rendu/Piscine_C_J04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  9 11:44:36 2015 louis-emile uberti-ares
** Last update Tue Dec 15 15:12:09 2015 louis-emile uberti-ares
*/

int	my_get_lenght(char *str)
{
  int	lenght;
  int	i;

  lenght = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	lenght *= 10;
      i += 1;
    }
  if (lenght != 1)
    lenght = lenght / 10;
  return (lenght);
}

int	my_getnbr(char *str)
{
  int	lenght;
  int	nb;
  int	rang;

  rang = 0;
  lenght = my_get_lenght(str);
  nb = 0;
  while ((str[rang] != '\0') && (lenght != 0))
    {
      if ((str[rang] >= '0') && (str[rang] <= '9'))
	{
	  nb = nb + lenght * (str[rang] - 48);
	  lenght = lenght / 10;
	}
      rang = rang + 1;
    }
  return (nb);
}
