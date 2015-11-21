/*
** my_getnbr.c for my_getnbr in /home/uberti_l/rendu/Piscine_C_J04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Oct  9 11:44:36 2015 louis-emile uberti-ares
** Last update Mon Nov 16 21:06:53 2015 louis-emile uberti-ares
*/

int	my_get_lenght(char *str)
{
  int	lenght;
  int	i;

  lenght = 1;
  i = 0;
  if (str[0] == '-')
    i = 1;
  while (str[i] != '\0')
    {
      i = i + 1;
      lenght = lenght * 10;
    }
  lenght = lenght / 10;
  return (lenght);
}

int	my_getnbr(char *str)
{
  int	lenght;
  int	nb;
  int	rang;

  rang = 0;
  if (str[0] == '-')
    rang = 1;
  lenght = my_get_lenght(str);
  nb = 0;
  while ((str[rang] != '\0') && (lenght != 0))
	{
	  nb = nb + lenght * (str[rang] - 48);
	  lenght = lenght / 10;
	  rang = rang + 1;
	}
  if (str[0] == '-')
    nb = -nb;
  return (nb);
}
