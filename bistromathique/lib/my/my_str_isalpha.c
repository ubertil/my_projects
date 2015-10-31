/*
** my_str_isalpha.c for my_str_isalpha in /home/uberti_l/rendu/Piscine_C_J06/ex_11
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 21:06:32 2015 louis-emile uberti-ares
** Last update Mon Oct 12 22:36:30 2015 louis-emile uberti-ares
*/

int	my_str_isalpha(char *str)
{
  int	count;
  int	garbage;

  garbage = 1;
  count = 0;
  while ((str[count] != '\0') && (garbage == 1))
    {
      if ((str[count] < 65) || ((str[count] > 90) && (str[count] < 97)) ||
	  (str[count] > 122))
	{
	  return (garbage);
	}
      count = count + 1;
    }
  garbage = garbage - 1;
  return (garbage);
}
