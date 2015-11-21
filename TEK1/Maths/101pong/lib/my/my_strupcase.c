/*
** my_strupcase.c for my_strupcase in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 11:39:06 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:42:51 2015 louis-emile uberti-ares
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 97) && (str[i] <= 122))
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
