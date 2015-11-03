/*
** my_strcapitalize.c for my_strcapitalize in /home/uberti_l/day06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 16:05:14 2015 louis-emile uberti-ares
** Last update Mon Oct 12 22:34:42 2015 louis-emile uberti-ares
*/


char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (((str[i] >= 97) && (str[i] <= 122)) &&
	((str[i - 1] == 32) || (str[i - 1] == 45 ) || (str[i - 1] == 43)))
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
