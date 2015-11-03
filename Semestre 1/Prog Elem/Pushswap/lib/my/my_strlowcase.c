/*
** my_strlowcase.c for my_strlowcase in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 13:10:00 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:41:58 2015 louis-emile uberti-ares
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] <= 90) && (str[i] >= 65))
	{
	  str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return (str);
}
